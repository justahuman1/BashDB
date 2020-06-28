# BashDB

## Table of Contents

1. [Introduction](#intro)
2. [Quickstart](#quickstart)
3. [Issues](#issues)
   1. [Why BashDB](#whyuse)
4. [Todo](#todo)

## What is BashDB? <a name="intro"></a>

BashDB aims to be a simple state manager for bash scripts. Rather than simply writing to individual files per script, this aims to provides a consolidated key-value store that is also faster than writing to disk. Furthermore, BashDB supports concurrency, in-memory caching, and aggressive data compression (via zlib).

### Why should I use BashDB? <a name="whyuse"></a>

- No stray files for individual scripts
- Simple get/put syntax
- Faster than writing to disk
- Supports concurrency
- Data compression on write
- In-memory caching
- Unified storage throughout scripts (less maintenance overhead)

## Quickstart <a name="quickstart"></a>

## Architecture

The relevant storage architecture for bash scripts is a key value store. Relational data is unlikely and reaching for relational objects in a bash scripts implies that bash was not the proper tooling for that particular application. BashDB is not a replacement for environment variables; thus, it is likely that the percentage of writes is equivalent of reads. As such, we optimize the data structure for writes first and then reads. The high level write to storage layer is as follows:

1. When a write comes in, add the record to a persistent log (disk) for crash-recovery purposes.

   - This maintains consistency in the database, as the client will immediately know if the write was successful. Any data not written to this log will not be recovered upon crashes/failure.

2. Add the persistent record to an in-memory balanced tree (AVL Tree), the memtable.
3. When the memtable gets bigger than some 32kB, BashDB will flush it out to disk as an SSTable file.
   - This can be done efficiently because the tree already maintains the key-value pairs sorted by key. The new SSTable file becomes the most recent segment of the database. While the SSTable is being written out to disk, writes can continue to a new memtable instance.
4. In order to serve a read request, BashDB will try to find the key in the memtable, then in the most recent on-disk segment, then in the next-older segment, and so on.
5. Every 50 puts (default), a merging and compaction run process in the background to combine segment files and to discard overwritten or deleted values.

## Issues <a name="issues"></a>

## Todo <a name="todo"></a>

- Buffer Manager
- Memtable
- SSTable
- CLI
- Compactor
