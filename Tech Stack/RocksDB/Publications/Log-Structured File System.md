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