# Experiment ID

EXP-001（对应 metrics.csv 中 EXP-B1）

## Purpose

测量单 MAC CFU 指令相对纯软件在 256 维点积上的加速比；
验证"每次迭代节省 ≈4 拍（mul FSM 停顿 + add），加速比受未加速部分限制"的预测。

## Compared with

纯软件 C 循环点积（Baseline），同一份数据、同一测量框架。

## Configuration

- 维度 N=256，int32；REPEAT=10 夹取，扣空夹开销
- 优化级别：-O0 / -Os / -O2 三组
- CFU 版：CFU_LOAD + 255×CFU_MAC + CFU_READ
- 平台：RVProc + Verilator 5，pg_perf cycle 计数

## Dataset

确定性公式初始化（无随机）：x[i]=(i*7+13)%251-125，w[i]=(i*11+29)%241-120

## Random seed

无随机数，固定公式保证完全可复现。

## Command

make OPT=-O0 && make run；make && make run（-Os）；make OPT=-O2 && make run

## Result

正确性逐位一致（c=-23637, cfu=-23637）。
cycle（单次 avg）：-O0: 7462 vs 6428；-Os: 2825 vs 1798；-O2: 2570 vs 1798
加速比：1.16 / 1.57 / 1.42

## Conclusion

-Os 下加速比 1.57x，落在预测区间 1.3–1.6 内；逐拍归因与预测一致。
优化级别越低加速比越趋近 1（绝对节省恒定、相对收益随基础开销缩水，Amdahl 定律）。
CFU 版在 -Os/-O2 下 cycle 不变（指令序列被 asm volatile 固定），
编译器优化只帮助软件版，会部分蚕食硬件加速比。

## Problems

无（本实验因编译器恰好将地址计算指令调度在 lw 与 CFU 之间，
未触发 load-use 冒险；该缺陷在 EXP-002 中暴露，见 issues.md #1）。