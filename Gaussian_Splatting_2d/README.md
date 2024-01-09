# GS的 cuda 代码
## forward 里面
![Alt text](assets/forward.png)
前两步在 preprocessCUDA
renderCUDA 中，设计比较巧妙的是 tile 当做 block，pixel 当做 thread
之后就是和 NeRF 的 Rendering 一样了。

## backward
![Alt text](assets/backward.png)
