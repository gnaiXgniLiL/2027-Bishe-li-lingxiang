# Experiment ID

EXP-002（对应 metrics.csv 中 EXP-B2）

## Purpose

测量单 MAC CFU 在 3x3 卷积上的加速比；验证预测"短 MAC 链摊薄 LOAD/READ
开销能力差，加速比将低于点积"。

## Compared with

纯软件 C 四重循环卷积（Baseline）。

## Configuration

- 输入 8x8、核 3x3、输出 6x6（valid 卷积，无 padding），int32；REPEAT=10
- 优化级别：-O0 / -Os / -O2 三组
- CFU 版采用预加载+完全展开结构（每像素 18 个操作数先取入寄存器，
  9 条 CFU 指令连续发射），规避 load-use 冒险（issues.md #1）；
  CFU_OP 宏含 3 nop 保险

## Dataset

确定性公式初始化：img[i]=(i*7+13)%251-125，kern[i]=(i*11+29)%241-120

## Random seed

无随机数。

## Command

同 EXP-001。

## Result

正确性 36/36 逐位一致（三级优化均通过）。
cycle（单次 avg）：-O0: 16872 vs 8052；-Os: 5311 vs 2068；-O2: 4944 vs 2063
加速比：2.09 / 2.56 / 2.39

## Conclusion

加速比 2.56x（-Os），**超出预测**（预测低于点积的 1.57）。
预测错误的原因：只考虑了 LOAD/READ 摊薄问题，未预见"预加载+展开"
消除了内层循环控制开销——加速收益 = MAC 指令节省 + 循环展开节省。
该结构（数据预取与计算分离、计算连续发射）是方案 B 设计的重要参考。

## Problems

初版（循环内 t/K、t%K 寻址）触发 custom-0 load-use 冒险，
对拍 5/36 且呈"行冻结"现象。定位过程与根因见 issues.md #1；
当前规避方案带 3 nop/指令的缺陷税，硬件修复（改 proc.v hazard 逻辑）待做。