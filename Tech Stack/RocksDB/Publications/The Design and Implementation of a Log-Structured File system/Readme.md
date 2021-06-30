# The Design and Implementation of a Log-Structured File system

## 1. Intorduction
- Disk Access time : CPU speeds have increased dramatically while disk access times have only improved slowly
- Disk Traffic : Read requests are effectively satisfied as memory grows in size -> So **write request** is matter
- Log라는 sequential structure에 디스크에 쓸 새로운 정보를 씀으로써 쓸위치를 찾는데 걸리는 시간을 줄인다.
- Crash가 발생할 경우 log의 최근 위치를 참조하여 빠르게 장애를 복구할 수 있다.
- 기존의 log개념을 도입한 FS는 log를 일시적으로 사용하였으나, Log-Structured FS는 데이터를 log에 영구적으로 저장한다.
- LSF에서는 데이터를 쓰기위해 항상 큰 free space가 필요한데 이를 segment라고 하며, segment cleaner를 통해 생성한다.
- 새로운 데이터를 쓰는데 기존 Unix system의 disk's bandwidth가 5~10%에 불과한 반면 본 논문에서 사용된 Sprite LFS는 약 65~75%의 disk's bandwidth를 가진다.

## 2. Design for file systems of the 1990's
### 2.1 Technology
- File system design has three significant components(Processors, Disks, and Main Memory).
- Disk performance depends on two components (Transfer bandwidth and access time).
- Disk is not better than before compared with CPU.
- 메인메모리의 용량이 증가함에 따라 더많은 양의 read requests와 write requests가 버퍼에 저장될 수 있게 되었다.

### 2.2 Workloads
- Small files usually result in small random disk I/Os, and the creation and deletion times for such files are often dominated by updates to file system `Metadata`
- Large files I/O performance tends to be limited by the bandwidth of the I/O and memory subsystems. 
- LSF에서는 작은 파일 접근의 효율화에 집중하고 있으며, 큰 파일의 경우 하드웨어의 대역폭 향상에 의존한다.
- Fortunately, the techniques used in Sprite LFS **work well for large files as well as small ones**

### 2.3 Problems with existing file systems
- Spread information around the disk in a way that causes too many samll accesses
- Tend to write synchronously : Application must wait for the write to complete

## 3. Log-structured file systems
**Fundamental Idea**
- Improve write performance by buffering a sequence of file system changes in the file cache and then writing all the changes to disk sequentially in a single disk **write operation**.  
  - The **write operation** include file data blocks, attributes, index blocks, directories, etc(used to manage the file system)
- LFS can convert **many small synchronous random writes** of traditional file systems into **large asynchronous sequential transfers** that can utilize nealy 100% of the raw disk bandwidth

**Issues** 
- How to retrieve information from the log
- How to manage the free space on disk so that large extents of free space are always available for writing new data

### 3.1 File location and reading
- In Sprite LFS inodes doesn't placed at fixed positions; **written to the log**
- To maintain the current location of each inode use data structure called `inode map`
- Fixed checkpoint region on each disk identifies the locations of all the inode map blocks.

### 3.2 Free space management : Segments
- By the time the log reaches the end of the disk the free space will have been fragmented into many small extents corresponding to the files that were deleted or overwritten

Solution 1 : Threading
- Leave the live data in place and thread the log trough the free extents.
- Free space become severely fragmented, so that large contigous writes won't be possible and LFS won't be faster than traditional FS. 

Solution 2 : Copying
- Copy the live data out of the log in order toleave large free exents for writing. 
- Long lived files will have to be copied in every pass of the log across the disk.

Sprite LFS = threading + copying

### 3.3 Segment cleaning mechanism
Segment cleaning : Copying live data out of segment
- Read number of segments into memory
- Identify the live data
- Write the live data back to smaller number of clean segments

Problem
- To update inode to point to the new locationi of the block
  - Which blocks of each segment are live
  - Which each block belongs and the position of the block within the file

Solution
- writing `segment summary block`
  - file number + block number

### 3.4 Segment Cleaning Policy
**Issues**
1. When should the segment cleaner execute
2. How many segments should it clean at a time
3. Which segments should be cleaned
4. How should the live blocks be grouped when they are written

Write cost
- Average amount of time the disk is busy per byte of new data written, including all the cleaning overheads
- Write Cost = 1 : New data could be written at the **full** disk bandwidth is actually used for writing new data
- Write Cost = 10 : Only **1/10 of disk's maximum bandwidth** is used for writing new data

### 3.5 Simulation results

Hot-and-Cold
- Hot : selected 90% of the time
- Cold : contains 90% of the files but selected only 10% of the time

