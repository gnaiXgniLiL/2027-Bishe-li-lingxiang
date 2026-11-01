# EXP03：C-unrolled 纯软件 baseline

## 实验目的

在 C-naive 与 CFU 之间加入 C-unrolled 版本，将总加速比拆分为：

1. 软件优化收益：C-naive → C-unrolled
2. 硬件净收益：C-unrolled → CFU

设三版平均周期分别为 T_naive、T_unrolled、T_cfu：

- X = T_naive / T_unrolled
- Y = T_unrolled / T_cfu
- 总加速比 = T_naive / T_cfu = X × Y

## 控制变量

三个版本使用相同的：

- 8×8 输入图像和 3×3 卷积核
- 6×6 valid 卷积输出
- 输入数据初始化方式
- 输出遍历结构
- REPEAT = 10
- cycle 测量与正确性对拍方法

C-unrolled 与 CFU 版本均采用：

- 9 个图像元素和 9 个卷积核元素预加载到局部变量
- 9 次乘加完全展开
- 无内层循环
- 不使用 nop

唯一有意差异：

- C-unrolled：普通 C 乘加
- CFU：LOAD + 8 次 MAC + READ

## 实验前预测

记录日期：2026-11-01

1. 正确性：-O0、-Os、-O2 下，C-unrolled 和 CFU
   均应通过 36/36 对拍。

2. 性能排序：预计
   T_naive &gt; T_unrolled &gt; T_cfu。

3. 软件优化收益 X：预计预加载与展开能减少内层循环、
   分支和重复地址计算开销，因此 C-unrolled 明显快于
   C-naive。

4. 硬件净收益 Y：由于 C-unrolled 与 CFU 已使用相同的
   预加载和展开结构，预计 Y 小于 naive 对 CFU 的总加速比。
   Y 主要反映普通 C 乘加与 CFU MAC 的实现差异。

5. 若实测不符合预测，保留原始数据，检查反汇编、寄存器
   分配和实验控制变量，不修改预测或原始结果。

## 实测结果

三档优化下，C-unrolled 与 CFU 均通过 36/36 正确性对拍。

| 优化档 | C-naive avg | C-unrolled avg | CFU avg | 软件收益 X | 硬件净收益 Y | 总加速比 |
|---|---:|---:|---:|---:|---:|---:|
| -O0 | 16872 | 8376 | 7296 | 2.014 | 1.148 | 2.312 |
| -Os | 5311 | 2394 | 1312 | 2.218 | 1.824 | 4.046 |
| -O2 | 4944 | 1867 | 1307 | 2.647 | 1.428 | 3.781 |

计算方式：

- X = C-naive total / C-unrolled total
- Y = C-unrolled total / CFU total
- 总加速比 = C-naive total / CFU total

CFU 三档 avg cycles 为 7296/1312/1307，与此前的
EXP-B2 nonop 记录完全一致，复现性良好。

## 预测与实测对照

1. 正确性符合预测：三档优化下两个测试版本均 36/36 通过。

2. 性能排序符合预测：所有优化档均满足
   T_naive &gt; T_unrolled &gt; T_cfu。

3. 软件优化收益明显：预加载与展开本身带来了
   2.014～2.647 倍加速，说明 naive → CFU 的总加速比
   不能全部归因于硬件。

4. 硬件净收益小于总加速比，符合预测：
   在相同预加载与展开结构下，CFU 进一步带来
   1.148～1.824 倍加速。

5. 与单纯乘加实现差异相比，软件结构优化是 -O0 档
   总加速比的主要来源；-Os 档的 CFU 硬件净收益最明显。

6. 三档均满足：总加速比 = X × Y。
   使用未舍入的 total cycles 计算时，该等式严格成立。