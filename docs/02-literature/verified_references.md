# 参考文献第一轮核验报告

核验日期：2026-10-04
数据来源：Google Scholar 检索
核验范围：《llx技术方案与参考文献建议.pdf》中 17 篇具体文献（排除 3 条"检索方向"）

---

## 一、核验总览

| 统计项 | 数量 |
| --- | --- |
| 总核验文献数 | 18 篇（PDF 中 20 条减去 3 条检索方向 + 本课题自找 1 篇） |
| 核实成功 | 14 篇 |
| 年份/信息有误 | 1 篇（Eyeriss 实际为 2016，PDF 写 2017） |
| 仅 arXiv 预印本 | 3 篇（CMSIS-NN、MLPerf Tiny、Yildirim 2025） |
| 筛选为核心文献 | 13 篇 |
| 精读 + 阅读卡 | 6 篇 |

---

## 二、核验详情

### [1] The RISC-V instruction set manual, volume I: unprivileged ISA

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | The RISC-V instruction set manual, volume I: unprivileged ISA | The RISC-V Instruction Set Manual<br>Volume I: Unprivileged ISA |
| 作者 | WATERMAN A, ASANOVIĆ K | Andrew Waterman, Krste Asanovi´c |
| 年份 | 2019 | 2019 |
| 出处 |  | RISC-V International |
| 状态 |  | 核实 |

**访问链接**：https://[docs.alexrp.com/riscv/riscv_unpriv_v1_0.pdf](https://docs.riscv.org/reference/isa/_attachments/riscv-unprivileged.pdf)

**相关性评级**： RISC-V指令集参考书

---

### [2] Instruction sets should be free: the case for RISC-V

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Instruction sets should be free: the case for RISC-V | Instruction sets should be free: The case for risc-v |
| 作者 | ASANOVIĆ K, PATTERSON D A | K Asanović, DA Patterson |
| 年份 | 2014 | **2014** |
| 出处 |  | UC Berkeley EECS Technical Report UCB/EECS-2014-146 |
| 状态 |  | 核实 |

**访问链接**(https://www2.eecs.berkeley.edu/Pubs/TechRpts/2014/Archive/EECS-2014-146.pdf)
**备注**：技术报告形式发表，非会议/期刊。

**相关性评级**：背景参考

---

### [3] CFU Playground: full-stack open-source framework for tiny machine learning acceleration on FPGAs

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | CFU Playground: full-stack open-source framework for tiny machine learning acceleration on FPGAs | Cfu playground: Full-stack open-source framework for tiny machine learning (tinyml) acceleration on fpgas |
| 作者 | PRAKASH S, CALLAHAN T, BUSHAGOUR J, et al. | S Prakash, T Callahan, J Bushagour… |
| 年份 | 2023 | **2023** |
| 出处 |  | IEEE International Symposium on Performance Analysis of Systems and Software (ISPASS) |
| 状态 |  | 核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/10158164/](https://arxiv.org/pdf/2201.01863)

**备注**：arXiv预印本编号2201.01863。

**相关性评级**： 必须引用（相关工作对比）

---

### [4] CFU Proving Ground: a Hardware/Software Co-Design Framework for Leveraging a Custom Function Unit and RISC-V Custom Instructions

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | CFU Proving Ground: a Hardware/Software Co-Design Framework for Leveraging a Custom Function Unit and RISC-V Custom Instructions | CFU Proving Ground: a Hardware/Software Co-Design Framework for Leveraging a Custom Function Unit and RISC-V Custom Instructions |
| 作者 | A Fujino, K Kise | A Fujino, K Kise |
| 年份 | 2025 | **2025** |
| 出处 |  | IEEE International Symposium on Multiple-Valued Logic (ISMVL) 或类似会议 |
| 状态 |  | 核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/11310862/](https://ieeexplore.ieee.org/abstract/document/11310862/figures#figures)

**相关性评级**：必须引用（本文平台）

---

### [5] Eyeriss: an energy-efficient reconfigurable accelerator for deep convolutional neural networks

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Eyeriss: an energy-efficient reconfigurable accelerator for deep convolutional neural networks | Eyeriss: An energy-efficient reconfigurable accelerator for deep convolutional neural networks |
| 作者 | CHEN Y H, KRISHNA T, EMER J S, et al. | YH Chen, T Krishna, JS Emer… |
| 年份 | 2017 | **2016** |
| 出处 |  | IEEE Journal of Solid-State Circuits (JSSC), 2016 |
| 状态 |  | 年份有误、核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/7738524/](https://ieeexplore.ieee.org/document/7738524)

**备注**：PDF中标注为2017，但实际发表年份为2016年（IEEE JSSC）。这是一处需要修正的错误。该工作为ASIC加速器，与FPGA方向有一定距离。

**相关性评级**：背景参考（ASIC方向）

---

### [6] In-datacenter performance analysis of a tensor processing unit

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | In-datacenter performance analysis of a tensor processing unit | In-datacenter performance analysis of a tensor processing unit |
| 作者 | JOUPPI N P, YOUNG C, PATIL N, et al. | NP Jouppi, C Young, N Patil, D Patterson… |
| 年份 | 2017 | **2017** |
| 出处 |  | Proceedings of the 44th ACM/IEEE International Symposium on Computer Architecture (ISCA) |
| 状态 |  | 核实 |

**访问链接**：[https://dl.acm.org/doi/abs/10.1145/3079856.3080246](https://dl.acm.org/doi/abs/10.1145/3079856.3080246)

**备注**：数据中心级ASIC加速器，与嵌入式FPGA+软核处理器方向差距较大。可作为加速器设计的一般性背景，但非核心相关文献。

**相关性评级**： 弱相关（背景）

---

### [7] Optimizing FPGA-based accelerator design for deep convolutional neural networks

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Optimizing FPGA-based accelerator design for deep convolutional neural networks | Optimizing FPGA-based accelerator design for deep convolutional neural networks |
| 作者 | ZHANG C, LI P, SUN G, et al. | C Zhang, P Li, G Sun, Y Guan, B Xiao… |
| 年份 | 2015 | **2015** |
| 出处 |  | Proceedings of the 2015 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA) |
| 状态 |  | 核实 |

**访问链接**：[https://dl.acm.org/doi/abs/10.1145/2684746.2689060](https://dl.acm.org/doi/abs/10.1145/2684746.2689060)

**备注**：高被引(2951次)。FPGA CNN加速器设计优化，与本课题直接相关。

**相关性评级**：中度相关

---

### [8] Going deeper with embedded FPGA platform for convolutional neural network

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Going deeper with embedded FPGA platform for convolutional neural network | Going deeper with embedded FPGA platform for convolutional neural network |
| 作者 | QIU J, WANG J, YAO S, et al. | J Qiu, J Wang, S Yao, K Guo, B Li, E Zhou… |
| 年份 | 2016 | **2016** |
| 出处 |  | Proceedings of the 2016 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA) |
| 状态 |  | 核实 |

**访问链接**：[https://dl.acm.org/doi/abs/10.1145/2847263.2847265](https://dl.acm.org/doi/abs/10.1145/2847263.2847265)

**备注**：高被引(1704次)。嵌入式FPGA平台CNN加速，与嵌入式场景高度相关。

**相关性评级**：中度相关

---

### [9] FINN: a framework for fast, scalable binarized neural network inference

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | FINN: a framework for fast, scalable binarized neural network inference | Finn: A framework for fast, scalable binarized neural network inference |
| 作者 | UMUROGLU Y, FRASER N J, GAMBARDELLA G, et al. | Y Umuroglu, NJ Fraser, G Gambardella… |
| 年份 | 2017 | **2017** |
| 出处 |  | Proceedings of the 2017 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA) |
| 状态 |  | 核实 |

**访问链接**：[https://dl.acm.org/doi/abs/10.1145/3020078.3021744](https://dl.acm.org/doi/abs/10.1145/3020078.3021744)

**备注**：专注于二值化神经网络(BNN)，本课题为INT8量化而非二值化。相关性中等偏低，可作为FPGA NN推理框架的参考。

**相关性评级**：弱相关

---

### [10] fpgaConvNet: a framework for mapping convolutional neural networks on FPGAs

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | fpgaConvNet: a framework for mapping convolutional neural networks on FPGAs | fpgaConvNet: A framework for mapping convolutional neural networks on FPGAs |
| 作者 | VENIERIS S I, BOUGANIS C S | SI Venieris, CS Bouganis |
| 年份 | 2016 | **2016** |
| 出处 |  | 2016 IEEE 24th Annual International Symposium on Field-Programmable Custom Computing Machines (FCCM) |
| 状态 |  | 核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/7544745/](https://ieeexplore.ieee.org/abstract/document/7544745/)

**备注**：FPGA CNN自动映射框架。本课题为手动RTL设计CFU，非自动化框架，但可作为相关工作对比。

**相关性评级**：弱相关

---

### [11] Near-threshold RISC-V core with DSP extensions for scalable IoT endpoint devices

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Near-threshold RISC-V core with DSP extensions for scalable IoT endpoint devices | Near-threshold RISC-V core with DSP extensions for scalable IoT endpoint devices |
| 作者 | GAUTSCHI M, SCHIAVONE P D, TRABER A, et al. | M Gautschi, PD Schiavone, A Traber… |
| 年份 | 2017 | **2017** |
| 出处 |  | IEEE Transactions on Very Large Scale Integration (VLSI) Systems |
| 状态 |  | 核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/7864441/](https://ieeexplore.ieee.org/abstract/document/7864441/)

**备注**：高被引(730次)。RISC-V处理器+DSP指令扩展，与RISC-V自定义指令方向非常接近。可作为指令扩展设计的直接参考。

**相关性评级**： 高度相关

---

### [12] PULP-NN: accelerating quantized neural networks on parallel ultra-low-power RISC-V processors

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | PULP-NN: accelerating quantized neural networks on parallel ultra-low-power RISC-V processors | PULP-NN: Accelerating quantized neural networks on parallel ultra-low-power RISC-V processors |
| 作者 | GAROFALO A, TAGLIAVINI G, CONTI F, et al. | A Garofalo, M Rusci, F Conti… (注: PDF中作者列表可能有误) |
| 年份 | 2020 | **2020** |
| 出处 |  | Philosophical Transactions of the Royal Society A |
| 状态 |  | 核实 |

**访问链接**：[https://royalsocietypublishing.org/rsta/article/378/2164/20190155/111584](https://royalsocietypublishing.org/rsta/article/378/2164/20190155/111584)

**备注**：高被引(245次)。RISC-V集群上的量化NN加速库，使用DSP扩展和并行性。与本课题（单核CFU自定义指令）技术路径不同但目标相同。PDF中作者列表与实际不符，需注意。

**相关性评级**：高度相关

---

### [13] CMSIS-NN: efficient neural network kernels for Arm Cortex-M CPUs

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | CMSIS-NN: efficient neural network kernels for Arm Cortex-M CPUs | Cmsis-nn: Efficient neural network kernels for arm cortex-m cpus |
| 作者 | LAI L, SUDA N, CHANDRA V | L Lai, N Suda, V Chandra |
| 年份 | 2018 | **2018** |
| 出处 |  | arXiv preprint arXiv:1801.06601 |
| 状态 |  | 无正式版 |

**访问链接**：[https://arxiv.org/abs/1801.06601](https://arxiv.org/abs/1801.06601)

**备注**：仅arXiv预印本，未找到正式发表版本。要求'arXiv已正式发表的一律引正式版'，若该文无正式版则只能以arXiv形式引用或放弃。作为Arm端优化参考，与RISC-V方向相关性一般。

**相关性评级**： 弱相关（架构不同）

---

### [14] TensorFlow Lite Micro: embedded machine learning for TinyML systems

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | TensorFlow Lite Micro: embedded machine learning for TinyML systems | Tensorflow lite micro: Embedded machine learning for tinyml systems |
| 作者 | DAVID R, DUKE J, JAIN A, et al. | R David, J Duke, A Jain… |
| 年份 | 2021 | **2021** |
| 出处 |  | Proceedings of Machine Learning and Systems (MLSys) |
| 状态 |  | 核实 |

**访问链接**：[https://proceedings.mlsys.org/paper/2021/hash/6c44dc73014d66ba49b28d483a8f8b0d-Abstract.html](https://proceedings.mlsys.org/paper/2021/hash/6c44dc73014d66ba49b28d483a8f8b0d-Abstract.html)

**备注**：TinyML软件框架。本课题偏硬件加速，相关性较弱，可作为TinyML应用背景。

**相关性评级**：弱相关

---

### [15] MLPerf Tiny benchmark

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | MLPerf Tiny benchmark | Mlperf tiny benchmark |
| 作者 | BANBURY C, REDDI V J, TORELLI P, et al. | C Banbury, VJ Reddi, P Torelli, J Holleman… |
| 年份 | 2021 | **2021** |
| 出处 |  | arXiv preprint arXiv:2106.07597 |
| 状态 |  | 无正式版 |

**访问链接**：[https://arxiv.org/abs/2106.07597](https://arxiv.org/abs/2106.07597)

**备注**：仅arXiv预印本，未找到正式发表版本。作为基准测试参考，与硬件加速方向相关性一般。

**相关性评级**：弱相关

---

### [16] Gradient-based learning applied to document recognition

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Gradient-based learning applied to document recognition | Gradient-based learning applied to document recognition |
| 作者 | LECUN Y, BOTTOU L, BENGIO Y, et al. | Y LeCun, L Bottou, Y Bengio… |
| 年份 | 1998 | **1998** |
| 出处 |  | Proceedings of the IEEE, 86(11): 2278-2324 |
| 状态 |  | 核实成功 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/726791/](https://ieeexplore.ieee.org/abstract/document/726791/)

**备注**：CNN经典文献(LeNet)，被引90734次。十分基础，仅在需要引用CNN历史背景时使用。

**相关性评级**：基础背景

---

### [17] Quantization and training of neural networks for efficient integer-arithmetic-only inference

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Quantization and training of neural networks for efficient integer-arithmetic-only inference | Quantization and training of neural networks for efficient integer-arithmetic-only inference |
| 作者 | JACOB B, KLIGYS S, CHEN B, et al. | B Jacob, S Kligys, B Chen, M Zhu… |
| 年份 | 2018 | **2018** |
| 出处 |  | IEEE/CVF Conference on Computer Vision and Pattern Recognition (CVPR) |
| 状态 |  | 核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/8578384/](https://ieeexplore.ieee.org/abstract/document/8578384/)

**备注**：高被引(7515次)。INT8量化推理的奠基工作。本课题使用INT8数据类型，该文为量化理论基础。

**相关性评级**：中度相关

---

### [18] Efficient processing of deep neural networks: a tutorial and survey

| 项目 | PDF 原文 | 核验结果 |
| --- | --- | --- |
| 标题 | Efficient processing of deep neural networks: a tutorial and survey | Efficient processing of deep neural networks: A tutorial and survey |
| 作者 | SZE V, CHEN Y H, YANG T J, et al. | V Sze, YH Chen, TJ Yang, JS Emer |
| 年份 | 2017 | **2017** |
| 出处 |  | Proceedings of the IEEE, 105(12): 2295-2329 |
| 状态 |  | 核实 |

**访问链接**：[https://ieeexplore.ieee.org/abstract/document/8114708/](https://ieeexplore.ieee.org/abstract/document/8114708/)

**备注**：高被引(6512次)。DNN高效处理综述，涵盖加速器设计、数据流、量化等。作为背景综述非常有价值。

**相关性评级**：中度相关（综述背景）

---

### [19] RISC-V Based TinyML Accelerator for Depthwise Separable Convolutions in Edge AI

| 项目 | 自己查找 | 核验结果 |
| --- | --- | --- |
| 标题 | RISC-V Based TinyML Accelerator for Depthwise Separable Convolutions in Edge AI | RISC-V Based TinyML Accelerator for Depthwise Separable Convolutions in Edge AI |
| 作者 | Muhammed Yildirim, Ozcan Ozturk | M Yildirim, O Ozturk |
| 年份 | 2025 | **2025** |
| 出处 |  | arXiv preprint arXiv:2511.21232 |
| 状态 |  | 仅 arXiv 预印本 |

**访问链接**：[https://arxiv.org/abs/2511.21232](https://arxiv.org/abs/2511.21232)

**备注**：自行检索到的论文。目前仅 arXiv 预印本，尚未检索到正式发表版本。但考虑到其与本课题的极端相关性（同平台类型、同板卡、同数据类型、同目标），密切关注其是否正式发表。

**相关性评级**：**最相关**

## 三、论文引用格式汇总（GB/T 7714-2015 著者-出版年制）

> 按论文末尾参考文献格式整理，西文姓全大写，作者与年份之间用逗号。
> 著录信息以第二节核验结果为准；标 ★ 的 6 篇已完成精读阅读卡（见第四节）。
> 仅 arXiv 预印本的条目按预印本格式著录，若正式发表须整条替换为正式版本。

[1] WATERMAN A, ASANOVIĆ K, 2019. The RISC-V instruction set manual, volume I: unprivileged ISA[EB/OL]. RISC-V International.

[2] ASANOVIĆ K, PATTERSON D A, 2014. Instruction sets should be free: the case for RISC-V[R]. Berkeley: UC Berkeley EECS (Technical Report UCB/EECS-2014-146).

[3] PRAKASH S, CALLAHAN T, BUSHAGOUR J, et al., 2023. CFU Playground: full-stack open-source framework for tiny machine learning (tinyML) acceleration on FPGAs[C]//Proceedings of the IEEE International Symposium on Performance Analysis of Systems and Software (ISPASS).

[4] ★ FUJINO A, KISE K, 2025. CFU Proving Ground: a hardware/software co-design framework for leveraging a custom function unit and RISC-V custom instructions[C]//IEEE International Symposium on Multiple-Valued Logic (ISMVL).

[5] CHEN Y H, KRISHNA T, EMER J S, et al., 2016. Eyeriss: an energy-efficient reconfigurable accelerator for deep convolutional neural networks[J]. IEEE Journal of Solid-State Circuits.（注意：PDF 原文误标 2017，已更正为 2016）

[7] ★ ZHANG C, LI P, SUN G, et al., 2015. Optimizing FPGA-based accelerator design for deep convolutional neural networks[C]//Proceedings of the 2015 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA '15). Monterey: ACM: 161-170.

[8] ★ QIU J, WANG J, YAO S, et al., 2016. Going deeper with embedded FPGA platform for convolutional neural network[C]//Proceedings of the 2016 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA '16). Monterey: ACM: 26-35.

[11] ★ GAUTSCHI M, SCHIAVONE P D, TRABER A, et al., 2017. Near-threshold RISC-V core with DSP extensions for scalable IoT endpoint devices[J]. IEEE Transactions on Very Large Scale Integration (VLSI) Systems, 25(10): 2700-2713.

[12] ★ GAROFALO A, RUSCI M, CONTI F, et al., 2020. PULP-NN: accelerating quantized neural networks on parallel ultra-low-power RISC-V processors[J]. Philosophical Transactions of the Royal Society A, 378(2164): 20190155.（注意：作者列表以核验结果为准，PDF 原文作者列表有误）

[16] LECUN Y, BOTTOU L, BENGIO Y, et al., 1998. Gradient-based learning applied to document recognition[J]. Proceedings of the IEEE, 86(11): 2278-2324.

[17] JACOB B, KLIGYS S, CHEN B, et al., 2018. Quantization and training of neural networks for efficient integer-arithmetic-only inference[C]//IEEE/CVF Conference on Computer Vision and Pattern Recognition (CVPR).

[18] ★ SZE V, CHEN Y H, YANG T J, et al., 2017. Efficient processing of deep neural networks: a tutorial and survey[J]. Proceedings of the IEEE, 105(12): 2295-2329.

[19] YILDIRIM M, OZTURK O, 2025. RISC-V based TinyML accelerator for depthwise separable convolutions in edge AI[EB/OL]. arXiv preprint arXiv:2511.21232.（仅 arXiv 预印本；与本课题最相关，持续关注是否正式发表）

---

## 四、精读阅读卡（6 篇）

---

### 阅读卡 1：Optimizing FPGA-based accelerator design for deep convolutional neural networks

- **作者 / 年份**：Chen Zhang, Peng Li, Guangyu Sun, Yijin Guan, Bingjun Xiao, Jason Cong / 2015
- **发表刊物**：Proceedings of the 2015 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA '15), Monterey, California, USA, pp. 161-170
- **被引次数**：约 2951 次（Google Scholar 数据）

**研究问题**

FPGA CNN 加速器的设计空间极其庞大。关键瓶颈在于：计算吞吐量与 FPGA 平台提供的内存带宽不匹配，导致现有方案要么逻辑资源未充分利用，要么内存带宽不足。如何系统性地探索这一设计空间，找到兼顾性能与资源开销的最优解？

**方法**

1. **Roofline 模型分析**：建立计算屋顶（computational roof）与带宽约束的关系，量化分析每种设计方案的理论吞吐与所需内存带宽
2. **循环平铺（Loop Tiling）**：将大尺度卷积分解为适合片上缓存的小块，减少外部 DRAM 访问
3. **多面体优化框架**：自动识别 CNN 代码中所有合法的循环变换（loop transformations）
4. **数据共享关系分类**：将循环维度与数组的访问关系分为 irrelevant / independent / dependent 三类，指导硬件连接拓扑设计
5. **本地内存提升（Local Memory Promotion）**：将冗余的外部内存访问提升到片上，减少通信量
6. **统一展开因子的跨层设计**：枚举各层最优展开因子后，选取统一的 (Tm, Tn) 组合用于整个 CNN，以 <5% 的性能损失换取硬件大幅简化

**数据/环境**

- **FPGA 平台**：Xilinx VC707（Virtex-7 VX485T）
- **工作频率**：100 MHz
- **开发工具**：Vivado HLS 2013.4 + Vivado 2013.4
- **软核处理器**：MicroBlaze（用于加速器启动、与主机通信、计时）
- **CNN 模型**：ImageNet 2012 竞赛用 8 层 CNN（前 5 层为卷积层，后 3 层全连接）
- **数据精度**：32-bit 浮点
- **对比基准**：Intel Xeon E5-2430 @ 2.20 GHz（1 线程与 16 线程软件实现）

**指标**

| 指标 | 数值 |
| --- | --- |
| 峰值性能 | **61.62 GFLOPS** @ 100 MHz |
| 相比 CPU 单线程加速比 | **17.42×** |
| 相比 CPU 16 线程加速比 | **4.8×** |
| FPGA 功耗 | 18.61 W |
| CPU 功耗 | 95 W |
| 能效比（vs CPU） | **24.6×** |
| DSP 利用率 | 2240 / 2800 = **80%** |
| BRAM 利用率 | 1024 / 2060 = **50%** |
| LUT 利用率 | 186251 / 303600 = **61.3%** |
| FF 利用率 | 205704 / 607200 = **33.87%** |
| 性能密度 | 8.12×10⁻⁴ GOPS/Slice（比当时第二名高 **1.8×**） |

**主要结论**

1. Roofline 模型是分析 FPGA CNN 加速器设计空间的有效工具，可清晰区分计算受限与带宽受限区域
2. 循环平铺 + 本地内存提升能将外部数据传输量降至理论最小值附近
3. 采用统一展开因子的跨层设计，在各层性能损失 <5% 的前提下，将硬件复杂度（控制逻辑、互联拓扑）大幅降低
4. 在 Virtex-7 上实现的加速器达到 61.62 GFLOPS，是当时已发表工作中性能最高的 FPGA CNN 加速器
5. FPGA 方案在功耗和能效上显著优于 CPU（24.6× 能效提升），展示了专用硬件的优势

**与自己课题的关系**

**中度相关**。本文是 FPGA CNN 加速器领域的经典高被引工作，但技术路线与本课题存在显著差异：

| 对比维度 | Zhang et al. (2015) | 李凌翔毕设 |
| --- | --- | --- |
| 处理器架构 | MicroBlaze 软核 + 专用加速器（外挂） | RISC-V 软核 + CFU 自定义指令（紧耦合） |
| 加速器规模 | 大规模专用 RTL（2240 DSP，树形 PE 阵列） | 轻量级 CFU（单 MAC → 方案 B 少量并行） |
| 数据精度 | 32-bit 浮点 | INT8 定点 |
| 目标网络 | ImageNet 级大型 CNN | TinyML 小型 CNN（LeNet 级或 MLPerf Tiny） |
| 设计方法 | HLS 高层次综合 + Roofline 模型指导 | 手工 RTL 设计 + 自定义指令扩展 |
| 应用场景 | 数据中心/高性能边缘 | 超低功耗嵌入式 IoT |

**可借鉴之处**：

- **资源–性能权衡的分析方法**：Roofline 模型可作为本课题方案 B 设计时的分析工具，判断是计算受限还是带宽受限
- **跨层统一设计的折中思路**：本课题若设计多种方案（如单 MAC vs 四并行 MAC），可借鉴"性能损失 <5% 换取硬件简化"的权衡逻辑
- **实验对比表格格式**：Table 5（与已有工作对比）、Table 6（资源利用率）、Table 7（与 CPU 对比）的格式可直接参考
- **性能密度指标**：GOPS/Slice 的归一化指标，可用于本课题不同方案之间的公平对比

---

### 阅读卡 2：Going deeper with embedded FPGA platform for convolutional neural network

- **作者 / 年份**：Jiantao Qiu, Jie Wang, Song Yao, Kaiyuan Guo, Boxun Li, Erjin Zhou, Jincheng Yu, Tianqi Tang, Ningyi Xu, Sen Song, Yu Wang, Huazhong Yang / 2016
- **发表刊物**：Proceedings of the 2016 ACM/SIGDA International Symposium on Field-Programmable Gate Arrays (FPGA '16), Monterey, California, USA, pp. 26-35
- **被引次数**：约 1704 次（Google Scholar 数据）

**研究问题**

如何在资源受限的嵌入式 FPGA 平台上高效部署完整的 CNN（包括卷积层和全连接层）进行 ImageNet 大规模图像分类？现有加速器大多只针对小型 CNN（如 LeNet）或仅加速卷积层，忽视了全连接层的严重带宽瓶颈。同时，固定精度的量化策略无法在不同层之间取得精度与资源开销的最佳平衡。

**方法**

1. **CNN 模型复杂度分析**：系统分析 CaffeNet、ZF、VGG11/16/19 等模型，发现卷积层（CONV）是计算密集型，全连接层（FC）是内存密集型，两者瓶颈不同
2. **动态精度数据量化（Dynamic-Precision Quantization）**：

- 自动搜索每层最优的定点数小数位长度（fractional length），在不同层和特征图集合之间动态调整精度
- 分为权重量化阶段和数据量化阶段，使用贪心算法逐层对比中间数据，最小化精度损失

3. **SVD 压缩全连接层**：对 FC6 层权重矩阵进行奇异值分解，将 25088×4096 分解为 25088×500 + 500×4096，权重从 103M 减至 14.6M（7.04× 压缩），精度损失仅 0.04%
4. **统一 PE 架构**：设计可重配置的 Processing Element（PE），包含 Convolver Complex（行缓冲 + 乘加树）、Adder Tree、Non-Linearity、Max-Pooling、Bias/ Data Shift 模块，统一处理 CONV 和 FC 层
5. **数据重排优化带宽**：

- CONV 层：将同一相对位置的 tile 连续存储，最大化 DMA burst 长度
- FC 层：将权重矩阵按块重排，从 64×100 次 DMA 事务降为 1 次，burst 长度更长

6. **CPU+FPGA 异构系统**：Zynq PS（ARM）负责调度和 Softmax，PL（FPGA）负责计算

**数据/环境**

- **FPGA 平台**：Xilinx Zynq ZC706（Kintex-7 FPGA + 双核 ARM Cortex-A9，1GB DDR3，4.2GB/s 带宽）
- **工作频率**：150 MHz
- **开发工具**：Xilinx Vivado 2014.4
- **CNN 模型**：VGG16-SVD（ImageNet ILSVRC 2014 训练集训练，验证集评估）
- **数据精度**：16-bit 动态精度定点数（8/4-bit 探索）
- **对比平台**：Intel Xeon E5-2690 CPU @ 2.90GHz（Caffe 框架）、Nvidia K40 GPU（2880 CUDA 核心）、Nvidia TK1 移动 GPU

**指标**

| 指标 | 数值 |
| --- | --- |
| CONV 层性能 | **187.8 GOP/s** |
| 完整 CNN 性能 | **137.0 GOP/s** @ 150 MHz |
| 帧率 | **4.45 fps** |
| Top-5 准确率（浮点） | 88.00% |
| Top-5 准确率（16-bit 动态量化） | **86.66%** |
| Top-5 准确率（8/4-bit 动态量化） | 86.30% |
| 量化精度损失（16-bit） | 仅 1.34% |
| FC6 层 SVD 压缩率 | **7.04×** |
| FF 利用率 | 127,653 / ? = **29.2%** |
| LUT 利用率 | 182,616 / ? = **83.5%** |
| DSP 利用率 | 780 / ? = **89.2%** |
| BRAM 利用率 | 486 / ? = **86.7%** |
| CPU 单线程耗时 | 316.64 ms |
| GPU (K40) 耗时 | 97.16 ms |
| FPGA 耗时 | 224.60 ms |

**主要结论**

1. **动态精度量化优于静态精度**：相比固定 16-bit 或 8-bit，动态精度量化可为不同层和特征图分配最适合的位宽，16-bit 动态量化仅损失 1.34% top-5 准确率，8/4-bit 动态量化仅损失 1.70%
2. **CONV 与 FC 层瓶颈不同**：CONV 层计算密集，需要强大的计算引擎；FC 层内存密集，受限于外部内存带宽。SVD 是缓解 FC 层带宽瓶颈的有效手段
3. **数据重排显著提升带宽利用率**：通过优化外部内存中的数据布局，将 DMA burst 长度最大化，减少事务开销
4. **统一 PE 设计可行**：通过可重配置的控制器指令，同一硬件可同时处理 CONV 和 FC 层，避免为不同层设计专用硬件
5. **嵌入式 FPGA 可运行完整 CNN**：在 Zynq ZC706 上实现 VGG16-SVD 端到端推理，4.45fps @ 86.66% top-5 准确率，验证了嵌入式 FPGA 上大规模 CNN 的可行性

**与自己课题的关系**

**中度相关**。同样是 FPGA CNN 加速，但技术路线和目标场景与本课题有显著差异：

| 对比维度 | Qiu et al. (2016) | 李凌翔毕设 |
| --- | --- | --- |
| 处理器架构 | ARM CPU + FPGA 加速器（外挂式） | RISC-V 软核 + CFU 自定义指令（紧耦合） |
| FPGA 平台 | Xilinx Zynq ZC706（Kintex-7 + ARM） | Nexys A7-100T（Artix-7，纯 FPGA） |
| 目标模型 | VGG16-SVD（大型 CNN，138M 权重） | 小型 CNN（LeNet 级或 MLPerf Tiny） |
| 数据精度 | 16-bit 动态精度定点 | INT8 定点 |
| 加速器规模 | 大规模（780 DSP，64 convolver/PE，2 PE） | 轻量级 CFU（单 MAC → 方案 B 少量并行） |
| 应用场景 | 嵌入式图像分类（4.45fps） | TinyML 超低功耗 IoT 推理 |
| 设计方法 | HLS + 手工 RTL（混合） | 纯手工 RTL + 自定义指令 |

**可借鉴之处**：

- **CNN 层特性分析**：本文对 CONV 层（计算密集）和 FC 层（内存密集）的区分分析，可帮助本课题理解自己模型中各层的瓶颈所在
- **量化策略分析框架**：Table 3 中不同量化策略（单浮点、16-bit 静态、16-bit 动态、8-bit 动态等）的对比方法，本课题可借鉴用于自己的 INT8 量化评估
- **资源利用率评估方法**：Table 5 中 FF/LUT/DSP/BRAM 利用率的报告方式，本课题可在 Vivado 综合后参考
- **数据重排思想**：虽然本课题当前是单 MAC 指令，但方案 B 若引入并行或流水线，数据排布对带宽利用的影响可参考本文
- **相关工作对比格式**：Table 7 与已有 FPGA 加速器的对比方式，本课题论文可直接参考

**需区分之处**：

- 本文使用 Zynq 的 ARM 硬核处理器，本课题使用的是 RISC-V 软核处理器，架构完全不同
- 本文目标是大型 CNN（VGG16），本课题目标是 TinyML 小型 CNN，资源约束和优化目标不同
- 本文加速器是独立的 IP 核，通过 AXI 与 CPU 通信；本课题是通过 RISC-V 自定义指令直接调用 CFU，耦合更紧密、延迟更低

---

### 阅读卡 3：Near-Threshold RISC-V Core With DSP Extensions for Scalable IoT Endpoint Devices

- **作者 / 年份**：Michael Gautschi, Pasquale Davide Schiavone, Andreas Traber, Igor Loi, Antonio Pullini, Davide Rossi, Eric Flamand, Frank K. Gürkaynak, Luca Benini / 2017
- **发表刊物**：IEEE Transactions on Very Large Scale Integration (VLSI) Systems, Vol. 25, No. 10, pp. 2700-2713
- **被引次数**：约 730 次

**研究问题**

物联网（IoT）端点设备需要在几毫瓦的功耗包络内运行，同时具备从 kOPS 到 GOPS 的计算可扩展性。如何在近阈值（Near-Threshold, NT）电压区域设计高能效的 RISC-V 处理器？如何通过指令集扩展和微架构优化提升计算密度，同时最小化对共享内存层次的压力？

**方法**

1. **ISA 扩展设计**：

- **硬件循环（Hardware Loops）**：通过专用硬件循环控制器消除分支开销，减少指令取指带宽压力
- **后增量寻址（Post-increment Addressing）**：自动更新指针，减少地址计算指令
- **定点运算支持（Fixed-point Support）**：Q-format 定点数加法、乘法、归一化、饱和（clip）指令
- **SIMD/子字并行**：8-bit（4 元素）和 16-bit（2 元素）向量操作，包括向量加减、比较、移位、逻辑运算
- **点积指令（Dot-product, dotp / sdotp）**：单周期内完成 4 对 8-bit 乘法 + 3 次加法 + 累加，或 2 对 16-bit 乘法 + 1 次加法 + 累加
- **Shuffle 指令**：任意重组两个寄存器中的子字元素，支持卷积窗口滑动时的数据重用
- **非对齐内存访问**：硬件支持非对齐加载，仅需 2 个周期（软件实现需 5 条指令）
- **位操作指令**：p.extract, p.insert, p.bclr, p.bset, p.cnt, p.ff1, p.fl1, p.clb

2. **微架构优化**：

- **四阶段流水线**：取指（IF）→ 译码（ID）→ 执行（EX）→ 写回（WB），暴露两个完整周期用于共享 TCDM 访问
- **L0 预取缓冲器（Prefetch Buffer）**：缓存 128-bit 缓存行（4-8 条指令），减少共享 I$ 访问冲突，支持压缩指令的非对齐跨越
- **时钟偏斜（Useful Skew）**：平衡 TCDM 请求和返回路径，提升频率
- **门控时钟**：未使用执行单元（ALU、乘法器、点积单元）的输入寄存器可被门控，降低 50% 动态功耗

3. **多核集群架构（PULP cluster）**：

- 4 核共享 72kB TCDM（SRAM+SCM 混合）和 4kB I$
- 对数互连（logarithmic interconnect）仲裁多核内存访问
- DVFS 支持：电压 0.32-1.15V，频率 40MHz-630MHz

4. **编译器支持**：

- 基于 GCC-5.2 修改 RISC-V 后端，自动检测硬件循环和后增量指针
- 提供 built-in 函数直接调用扩展指令（如 `__builtin_pulp_dotsp2`）

**数据/环境**

- **工艺**：65nm UMC LL CMOS（主实验）+ 28nm FDSOI（NT 能效对比）
- **平台**：PULP 多核集群（4 核 RISC-V RV32IM + 扩展）
- **综合/布局布线**：Synopsys Design Compiler 2016.03 + Cadence Innovus 15.20.100
- **仿真**：Mentor QuestaSim 10.5a，反标注门级网表
- **基准测试**：
- 通用：CoreMark
- 密码学：crc, sha, aes, keccak
- 控制密集型：fibonacci, bubblesort
- 信号处理：FFT, FDCT, FIR, 2D 滤波器
- 线性代数：矩阵加法、矩阵乘法
- **卷积**：3×3, 5×5, 7×7 Gaussian filter on 64×64 image
- 实际应用：运动检测

**指标**

| 指标 | 数值 |
| --- | --- |
| 面积（集群 A：基础 RISC-V） | 1.30 MGE |
| 面积增加（扩展部分） | +6.6 kGE（仅 +2%） |
| 面积（ALU 扩展） | +8.3 kGE |
| 面积（乘法器扩展） | +12.6 kGE |
| 频率（65nm） | 350-400 MHz |
| 频率（28nm FDSOI） | 630 MHz |
| 单核功耗（50MHz, 1.08V） | 4 mW（核心占 35%） |
| 空闲核心功耗 | 仅 2.8%（83% 为漏电） |
| CoreMark 分数 | 3.19 |
| 通用应用加速（硬件循环+后增量） | **平均 37%** |
| 向量化内核加速（built-ins） | 最高 **13.2×**，平均 **3.5×** |
| 卷积加速（单核，含 dotp/shuffle） | **2.2-6.9×** |
| 卷积每像素周期（5×5, 基础） | ~130 cycles |
| 卷积每像素周期（5×5, 扩展+built-ins） | ~26 cycles |
| 能耗提升（扩展 vs 基础） | **平均 3.2×** |
| TCDM 访问冲突减少（shuffle + RF 作 L0） | **8.3×**（11100 → 390） |
| 65nm 峰值能效 | **67 MOPS/mW** |
| 28nm FDSOI NT 峰值能效 | **193 MOPS/mW**（40MHz, 1mW） |
| 多核线性加速（4 核矩阵乘法） | **3.9×**（接近理想） |
| 多核能耗节省（4 核 vs 单核） | **1.6×** |

**主要结论**

1. **ISA 扩展以极小的面积代价带来显著性能提升**：扩展仅增加 2% 面积，但通用应用加速 37%，数据密集型内核加速 3.5×，卷积加速最高 6.9×
2. **点积指令是数据密集型应用的关键**：dotp/sdotp 单周期完成 4 次 8-bit 乘法 + 累加，使 5×5 卷积从 25 条 mac 指令降至 7 条 sdotp 指令
3. **Shuffle + RF 作为 L0 存储减少内存带宽压力**：通过寄存器内数据重用，将 TCDM 访问冲突降低 8.3×，加载指令减少 8×
4. **近阈值操作实现超高能效**：28nm FDSOI 在 NT 区域达到 193 MOPS/mW（5.2 pJ/op），优于当时最好的 MCU（10 pJ/op）
5. **多核架构在 NT 区域可扩展**：4 核集群在保持能效的同时实现近线性加速（3.9×），功率仅增加 2.4×，净能耗节省 1.6×
6. **编译器自动利用扩展**：无需手写汇编，GCC 自动检测硬件循环和后增量模式，built-in 函数暴露 SIMD/点积指令

**与自己课题的关系**

**高度相关**。本文是 RISC-V 指令扩展（特别是 DSP/MAC 扩展）领域的奠基性工作，与本课题的技术路线（通过自定义指令加速 CNN 推理）高度一致：

| 对比维度 | Gautschi et al. (2017) | 李凌翔毕设 |
| --- | --- | --- |
| 核心方法 | RISC-V ISA 扩展（dotp, mac, shuffle, SIMD） | RISC-V 自定义指令（CFU 接口 + MAC） |
| 扩展层级 | 处理器核心内部（修改 EX 级） | 核心外部（CFU 作为协处理器） |
| 数据类型 | 8-bit / 16-bit 定点 | INT8 定点 |
| 目标应用 | 通用信号处理（卷积、滤波、FFT、矩阵） | CNN 推理（卷积、点积） |
| 并行度 | 4-way SIMD（8-bit） | 单 MAC（方案 A）→ 多并行（方案 B） |
| 处理器数量 | 多核集群（4 核共享内存） | 单核 RISC-V |
| 平台 | ASIC（65nm/28nm） | FPGA（Artix-7） |
| 编译器 | GCC + built-ins | 自定义内联汇编 / C 封装函数 |

**可直接借鉴的内容**：

1. **点积/MAC 指令设计思路**：本文 dotp（4×8-bit 乘法+累加）和 sdotp（带累加输入）的设计与本课题 CFU 的 mulacc 指令功能一致，可作为指令功能设计的参考
2. **编译器对接方式**：本文通过 GCC built-in 函数暴露扩展指令，本课题当前使用 C 函数 `cfu_op(funct3, a, b)` 封装——未来可考虑向编译器内置函数演进
3. **卷积性能评估方法**：Fig. 11 中"cycles per output pixel"的评估指标，本课题可直接用于自己的 conv3x3 算子评估
4. **性能对比表格格式**：Fig. 10 中 IPC、Speedup、Energy-efficiency gains 的三图并排格式，本课题论文可参考
5. **资源开销报告方式**：Table V 中与其他架构（OpenRISC, ARM Cortex-M4）的面积/性能/功耗对比，本课题可在相关工作章节参考

**需明确区分的内容**：

1. **扩展实现位置不同**：本文是在处理器流水线内部增加 EX 级执行单元（紧耦合），本课题是通过 CFU 接口在核心外部实现（松耦合）。CFU 方式更灵活但延迟更高（需通过自定义指令编码/解码）
2. **并行度不同**：本文利用 4-way SIMD 并行处理 4 对 8-bit 数据，本课题当前是标量 MAC（一次处理一对 32-bit 操作数中的 8-bit 数据）。方案 B 若引入并行 MAC，可向本文的 SIMD 思路靠拢
3. **应用场景不同**：本文面向通用信号处理（涵盖 FIR、FFT、矩阵等），本课题专注于 CNN 推理。CNN 中的卷积和点积是信号处理中卷积和矩阵乘法的特例
4. **能耗优化维度不同**：本文重点在 NT 电压区域和门控时钟降低功耗，本课题在 FPGA 上主要关注 LUT/DSP 资源消耗和时钟频率

---

### 阅读卡 4：PULP-NN: accelerating quantized neural networks on parallel ultra-low-power RISC-V processors

- **作者 / 年份**：Angelo Garofalo, Manuele Rusci, Francesco Conti, Davide Rossi, Luca Benini / 2020（发表于 2019，实际引用常以 2020 计）
- **发表刊物**：Philosophical Transactions of the Royal Society A, Vol. 378, Issue 2164, 20190155
- **被引次数**：约 245 次（Google Scholar 数据）

**研究问题**

如何在资源受限的 IoT 边缘设备上高效执行量化神经网络（QNN）推理？现有方案要么依赖高功耗 FPGA/GPU，要么依赖单核 MCU 无法利用并行性。MCU 类设备功耗虽低（mW 级），但内存和计算能力有限，难以满足 CNN 推理的延迟和精度要求。量化（INT-8、INT-4、INT-2、INT-1）可减少内存和计算量，但缺乏充分利用这些低精度数据类型的并行软件库。

**方法**

1. **PULP-NN 软件库**：开源 QNN 推理计算库，基于 CMSIS-NN 数据流，支持 INT-8/4/2/1 量化数据类型，面向 PULP（Parallel Ultra-Low-Power）RISC-V 处理器集群优化
2. **利用 RISC-V DSP 扩展（Xpulp）**：

- **SIMD 点积指令**：`sdotp4`（4×8-bit 点积+累加，单周期）、`sdotp2`（2×16-bit 点积+累加）
- **向量数据类型**：`v4s`（4 个 INT-8）、`v2s`（2 个 INT-16），单周期打包/解包
- **硬件循环（HW Loop）**：消除分支开销
- **后增量加载（Post-increment LD/ST）**：自动更新指针，减少地址计算指令
- **位操作指令**：`bextract`（位提取）、`pack4`（打包）、`bitinsert`（插入）、`popcnt`（popcount）

3. **im2col + 矩阵乘法数据流**（继承 CMSIS-NN）：

- 卷积分解为 im2col 展开 + 矩阵乘法
- 数据布局：HWC（Height-Width-Channel），沿通道方向 stride=1
- 矩阵乘法内核尺寸探索：1×2 → 2×2 → 4×2 → 2×4，通过寄存器级数据重用最大化 MAC/load 比

4. **多核并行优化**：

- 沿输出特征图空间维度分块，每核计算完整输出通道的私有空间区域
- 每核私有 im2col 缓冲（最坏情况额外内存开销约 9%）
- 权重共享，通过 OpenMP 并行

5. **Sub-byte 支持**：

- INT-4：两个元素打包在一个字节，用 `bextract` + `pack4` 解包，矩阵乘法后通过阶梯函数（staircase function，平衡二叉树比较）压缩回 INT-4
- INT-2：类似打包/解包流程
- INT-1：XNOR + popcount 替代乘法，二值卷积专用路径

**数据/环境**

- **目标平台**：
- GAP8 商用 SoC（GreenWaves Technologies），8 核 RISC-V 集群，64kB L1 TCDM，4kB 共享 I$
- 也可在开源 PULP 平台（RTL 仿真）复现
- **处理器核心**：RI5CY（RISC-V RV32IM + Xpulp DSP 扩展），四阶段单发射流水线
- **CNN 模型**：CIFAR-10 量化网络（卷积占约 96% 计算量）
- **数据类型**：INT-8、INT-4、INT-2、INT-1
- **对比基准**：
- RV32IMC（纯 RISC-V，无扩展）
- ARM CMSIS-NN on STM32L476（Cortex-M4）
- ARM CMSIS-NN on STM32H743（Cortex-M7）
- GWT-NN（GreenWaves Technologies 官方专有库）

**指标**

| 指标 | 数值 |
| --- | --- |
| 峰值吞吐（8 核 INT-8，4×2 内核） | **15.5 MACs/cycle** |
| MAC 利用率 | **49%**（理论峰值 32 MACs/cycle 的约一半） |
| LD/ST 每 MAC | **1.01**（接近理想值） |
| 单核 INT-8 加速（vs RV32IMC） | **8.8×** |
| 单核 INT-4 加速（vs RV32IMC） | **3.69×** |
| 单核 INT-2 加速（vs RV32IMC） | **4.22×** |
| 单核 INT-1 加速（vs RV32IMC） | **2.22×** |
| 8 核 INT-8 加速（vs RV32IMC 单核） | **63×** |
| 8 核并行效率 | **7.16×**（接近线性） |
| vs STM32H7（Cortex-M7，INT-8） | **2.54×** 更快 |
| vs STM32L4（Cortex-M4，INT-8） | **4.51×** 更快 |
| vs STM32H7（Cortex-M7，INT-4） | **1.42×** 更快 |
| vs STM32L4（Cortex-M4，INT-4） | **2.1×** 更快 |
| vs GWT-NN（最优配置） | 最高 **+89%** 加速 |
| GAP8 能效（vs STM32L4） | **14.1×** 更高 |
| GAP8 能效（vs STM32H7） | **39.5×** 更高 |

**主要结论**

1. **DSP 扩展带来数量级加速**：单核上，利用 `sdotp4` + 硬件循环 + 后增量加载，INT-8 卷积比纯 RISC-V 快 8.8×，比 ARM Cortex-M7（CMSIS-NN）快 2.54×，比 Cortex-M4 快 4.51×
2. **多核近线性扩展**：8 核集群实现 7.16× 加速（理想 8×），主要开销来自 I$ 冲突（67%）、TCDM 冲突（20%）、加载停顿（8%）
3. **矩阵乘法内核尺寸关键**：4×2 内核达到 15.5 MACs/cycle 峰值，MAC/load = 5.33；内核尺寸受限于 32 个通用寄存器（4×4 需要 24 个寄存器导致 spill）
4. **Sub-byte 可行但有解包开销**：INT-4/INT-2 需要 `bextract`+`pack4` 解包，开销使加速比从 8.8× 降至 3.69×/4.22×，但仍优于 ARM MCU
5. **INT-1 利用位运算**：二值卷积用 XNOR+popcount 替代乘法，实现 2.22× 加速，但精度损失需通过重训练弥补
6. **开源生态价值**：PULP-NN 作为开源库，展示了在可编程 MCU 上实现专用加速器级别能效的可行性，为边缘 AI 提供了灵活的软件方案

**与自己课题的关系**

**高度相关**。本文是 RISC-V + 量化 NN + 软件优化的标杆工作，与本课题目标相同（在 RISC-V 平台上加速 INT8 CNN 推理），但技术路径不同：

| 对比维度 | PULP-NN (Garofalo et al., 2020) | 李凌翔毕设 |
| --- | --- | --- |
| 核心方法 | 多核并行 + SIMD DSP 指令扩展（软件库优化） | 单核 CFU 自定义指令（硬件 RTL 设计） |
| 处理器 | 8 核 RISC-V 集群（RI5CY + Xpulp） | 单核 RISC-V（RV32IM + CFU） |
| 并行性 | 8 核 + 4-way SIMD（8-bit） | 标量（方案 A）→ 少量并行（方案 B） |
| 数据精度 | INT-8/4/2/1 | INT-8 |
| 实现层级 | 软件库（C + built-in） | 硬件 RTL（Verilog）+ C 封装 |
| 内存架构 | 64kB 共享 TCDM + DMA | 片上 SRAM（CFU-Proving-Ground 平台） |
| 编译器 | GCC + OpenMP + built-ins | 自定义内联汇编 / C 函数封装 |
| 峰值吞吐 | 15.5 MACs/cycle（8 核） | 1 MAC/cycle（方案 A）→ 待定义（方案 B） |

**可借鉴之处**：

1. **卷积数据流设计**：im2col + 矩阵乘法的分解方式，本课题实现 conv3x3 时可参考其循环结构和数据布局
2. **MAC/load 比优化思想**：PULP-NN 通过寄存器级数据重用将 LD/ST 降至 1.01/MAC，本课题在方案 B 设计时需考虑类似问题（CFU 接口的数据供给带宽）
3. **量化推理流程**：从 INT8 卷积 → INT32 累加 → 缩放/截断回 INT8 的完整流程，与本课题 INT8 实现一致
4. **性能对比基准**：PULP-NN 的 INT-8 单核 8.8× 加速（vs 纯 RISC-V）可作为本课题方案加速比的参考锚点。若本课题单 MAC CFU 能达到 2-5×，已接近软件优化上限；若方案 B 引入并行 MAC，目标可设更高
5. **多精度对比方法**：论文对 INT-8/4/2/1 的逐级对比方式，本课题若未来扩展 INT4/INT16 可参考其实验设计

**需明确区分的内容**：

1. **软件 vs 硬件**：PULP-NN 是纯软件优化（利用现有 ISA 扩展），本课题是硬件设计（自定义 CFU RTL）。两者可互补：PULP-NN 展示了软件优化的上限，本课题的 CFU 是突破该上限的硬件手段
2. **多核 vs 单核**：PULP-NN 的核心优势来自多核并行（8 核贡献 ~7× 加速），本课题是单核架构。绪论中需说明"本文不依赖多核并行，而是通过单核内的自定义指令实现加速"
3. **平台不同**：PULP-NN 跑在 GAP8（65nm ASIC）上，本课题是 FPGA（Artix-7）。GAP8 的能效数据（193 MOPS/mW）不能直接对标 FPGA
4. **指令获取方式**：PULP-NN 的 SIMD 指令是处理器原生支持的（编译器直接生成），本课题的 CFU 指令需要通过自定义 opcode 和内联汇编调用

---

### 阅读卡 5：Efficient Processing of Deep Neural Networks: A Tutorial and Survey

- **作者 / 年份**：Vivienne Sze, Yu-Hsin Chen, Tien-Ju Yang, Joel S. Emer / 2017
- **发表刊物**：Proceedings of the IEEE, Vol. 105, No. 12, pp. 2295–2329
- **被引次数**：约 6512 次（Google Scholar 数据）

**研究问题**

深度神经网络（DNN）在计算机视觉、语音识别和机器人等领域取得了突破性进展，但伴随而来的是极高的计算复杂度。如何在保持应用精度的同时，提升 DNN 处理的能效和吞吐、降低硬件成本？本文试图回答：有哪些关键技术可用于高效处理 DNN？这些技术如何在算法、架构和电路三个层面协同作用？

**方法**

本文是一篇**综述/教程**性质的文章，系统梳理了 DNN 高效处理的完整技术谱系：

1. **DNN 基础回顾**：

- 全连接层（FC）、卷积层（CONV）、激活函数（ReLU、Sigmoid、Tanh）
- 训练 vs 推理：训练通过反向传播和梯度下降更新权重；推理仅前向传播
- 流行模型：LeNet、AlexNet、VGGNet、GoogLeNet（Inception）、ResNet 等

2. **硬件平台分析**：

- **CPU/GPU**：利用 SIMD/SIMT 并行执行 MAC，通过矩阵乘法映射 FC 和 CONV 层
- **FPGA**：可重构硬件，支持任意精度定点运算，适合原型验证和小批量部署
- **ASIC**：定制加速器（如 Eyeriss、TPU、DaDianNao），能效最高但灵活性最低
- **数字信号处理器（DSP）**：专用 MAC 单元，适合低功耗嵌入式场景

3. **数据流优化（Dataflow）**：

- **Weight Stationary (WS)**：权重驻留 PE 本地，最小化权重读取能耗
- **Output Stationary (OS)**：输出部分和驻留本地，最小化输出写回能耗
- **No Local Reuse (NLR)**：无本地存储，最大化全局缓冲器容量
- **Row Stationary (RS)**：Eyeriss 提出的混合数据流，按行处理，平衡三种复用

4. **近数据计算（Near-Data Processing）**：

- eDRAM、3D 存储（HMC/HBM）、计算存储一体（Processing-in-Memory）
- 新型存储器：ReRAM、PCM、STT-MRAM、FeFET 等用于存内计算

5. **算法-硬件协同优化**：

- **量化（Quantization）**：
    - 均匀量化：8-bit 定点权重和激活，精度损失极小（<1%）
    - 二值/三值网络：权重限制为 ±1 或 {−w, 0, w}，大幅简化乘法为 XNOR
    - 非均匀量化：对数量化、学习型量化
- **剪枝（Pruning）**：
    - 权重剪枝：移除小权重，稀疏矩阵存储（CSR/CSC）
    - 激活剪枝：跳过零值激活的 MAC 计算
- **紧凑网络设计**：
    - SqueezeNet：1×1 卷积减少参数
    - MobileNet：深度可分离卷积（Depthwise Separable）
    - ShuffleNet：通道shuffle减少 1×1 卷积成本
- **知识蒸馏**：用大网络（教师）指导小网络（学生）训练

6. **评估指标**：

- 吞吐量（Throughput）、延迟（Latency）、能效（Energy Efficiency）
- 性能密度（Performance Density，如 GOPS/mm²）
- 成本指标：芯片面积、功耗、片外内存带宽需求

**数据/环境**

- **涵盖平台**：CPU（Intel Xeon）、GPU（Nvidia K40/ Titan X）、FPGA（Xilinx/Altera）、ASIC（Eyeriss、TPU、DaDianNao 等）
- **涵盖模型**：从 LeNet 到 ResNet、从图像分类到目标检测、语音识别
- **精度基准**：ImageNet 图像分类的 top-1/top-5 错误率

**指标**

| 指标/数据点 | 数值 |
| --- | --- |
| 8-bit 定点加法 vs 32-bit 浮点加法 | **30×** 能耗降低，**116×** 面积降低 |
| 8-bit 定点乘法 vs 32-bit 浮点乘法 | **18.5×** 能耗降低，**27.5×** 面积降低 |
| 8-bit 定点乘法 vs 32-bit 定点乘法 | **15.5×** 能耗降低，**12.4×** 面积降低 |
| 权重稀疏化（AlexNet） | **9×** 权重减少，**3×** MAC 减少 |
| 激活稀疏化（ReLU） | 平均 **44%** 激活为零 |
| SqueezeNet 参数 vs AlexNet | **50×** 减少，精度相当 |
| MobileNet 计算量 vs 标准卷积 | **8–9×** 减少 |

**主要结论**

1. **数据移动是能耗瓶颈**：从 DRAM 读取数据的能耗是做一次 MAC 的数百倍，因此数据复用（data reuse）是加速器设计的核心
2. **数据流决定能效上限**：不同的数据流（WS/OS/RS）在不同网络层和硬件约束下各有优势，没有 universally optimal 的数据流
3. **8-bit 定点是精度与效率的 sweet spot**：8-bit 量化在几乎所有网络上都能保持 <1% 精度损失，同时带来 15–30× 的运算能耗降低
4. **算法与硬件必须协同设计**：仅靠硬件优化（如更多并行度）或仅靠算法优化（如剪枝）都有天花板，联合优化才能突破
5. **专用加速器是趋势，但可编程性不可忽视**：ASIC 能效最高，但 DNN 算法演进快，FPGA 和可编程加速器（如 TPU）在灵活性和效率之间取得平衡
6. **评估需用统一指标**：不同工作使用不同指标（GOPS、帧率、能耗等），直接对比困难，建议用 Roofline 模型和归一化指标（如 GOPS/W、GOPS/mm²）

**与自己课题的关系**

**中度相关（综述背景）**。本文是 DNN 高效处理领域的权威综述，为本课题提供了**整体认知框架**和**技术定位坐标**：

| 对比维度 | Sze et al. (2017) | 李凌翔毕设 |
| --- | --- | --- |
| 文章类型 | 综述/教程 | 具体实现研究 |
| 覆盖范围 | CPU/GPU/FPGA/ASIC/DSP 全平台 | 仅 FPGA + RISC-V 软核 |
| 技术深度 | 广度优先（介绍各种技术） | 深度优先（单一技术路线） |
| 优化层面 | 算法+架构+电路三层 | 架构层（自定义指令） |
| 数据精度 | 涵盖 FP32/INT16/INT8/二值 | INT8 |
| 应用场景 | 从数据中心到嵌入式全覆盖 | TinyML 嵌入式 IoT |

**可借鉴之处**：

1. **技术定位框架**：本文 Fig. 2（DNN 设计空间：精度 vs 硬件成本）可帮助本课题在绪论中说明"本文工作处于 DNN 高效处理研究中的哪个位置"——即在 INT8 量化 + FPGA + RISC-V 自定义指令这个交叉点上
2. **数据流概念**：WS/OS/RS 三种数据流的介绍，可帮助本课题理解方案 B 中不同并行策略（如 Weight Stationary vs Output Stationary）的权衡
3. **量化论据**：第 VII-A 节中 8-bit 量化的精度损失数据（Table 3）和能耗降低数据（30×/18.5×），可直接用于本课题论文中解释"为什么选择 INT8"
4. **评估指标**：本文提出的 Roofline 模型、GOPS/W、GOPS/mm² 等归一化指标，本课题可用于方案 A 和方案 B 的公平对比
5. **相关工作组织方式**：本文按"平台→数据流→近数据计算→算法-硬件协同"的层次组织，本课题论文的相关工作章节可参考此结构

**需明确区分的内容**：

1. 本文是综述，不提出具体实现；本课题论文需要展示具体的 RTL 设计和实验结果
2. 本文覆盖全平台，本课题只聚焦 FPGA + RISC-V 软核
3. 本文讨论的技术（如 3D 存储、ReRAM、二值网络）超出本课题当前范围，引用时需注意不要过度展开

---

### 阅读卡 6：CFU Proving Ground: a hardware/software co-design framework for leveraging a custom function unit and RISC-V custom instructions

- **作者 / 年份**：Aoba Fujino, Kenji Kise / 2025
- **发表刊物**：IEEE International Symposium on Multiple-Valued Logic (ISMVL) 2025
- **被引次数**：约 0–3 次（刚发表）

**研究问题**

应用专用指令集处理器（ASIP）的开发周期长，硬件与软件设计往往脱节。现有硬件/软件协同设计框架（如 CFU Playground）虽然提供了完整流程，但存在依赖复杂、许可证冲突、学习成本高的问题。如何提供一个**轻量级、易扩展、低学习成本**的 CFU 设计与评估框架，使开发者能够快速迭代 ASIP 设计？

**方法**

1. **轻量级框架设计**：

- 仅 23 个文件、2,681 行代码（Verilog HDL + C）
- 单一 MIT 许可证，消除 CFU Playground 的多许可证依赖问题
- 显式文件依赖关系，无隐藏依赖

2. **完整的敏捷开发流程**：

- **Step 1：性能分析** — 使用 `pg_perf` 库（硬件性能计数器）定位 C 程序瓶颈
- **Step 2：CFU 设计** — 支持 RTL（Verilog）和 HLS（C 综合）两种路径
- **Step 3：仿真验证** — Verilator 快速仿真 + LCD 显示模拟器
- **Step 4：FPGA 验证** — Vivado 综合生成比特流，实板运行

3. **SoC 架构**：

- **RVProc**：自研 5 级流水线 RISC-V 处理器（RV32IM），含分支预测器（BTB）
- **CFU 接口**：`en_i`, `funct3_i[2:0]`, `funct7_i[6:0]`, `src1_i[31:0]`, `src2_i[31:0]`, `stall_o`, `rslt_o[31:0]`
- **内存**：32 KiB 指令 BRAM + 16 KiB 数据 BRAM（可配置）
- **MMIO 显示**：240×240 像素 LCD，24 KiB 显存

4. **软件支持**：

- `cfu_op(funct7, funct3, rs1, rs2)` — GCC 内联汇编封装，生成 R-type custom 指令
- `pg_perf_enable()` / `pg_perf_disable()` / `pg_perf_cycle()` — 硬件性能计数
- `pg_lcd_print()` / `pg_lcd_printd()` — 显示输出

5. **两个案例研究**：

- **N-Queens**：用 CFU 加速回溯算法的位运算核心，3 天完成设计与实现
- **FFT**：用 CFU 加速定点复数蝶形运算（mul/sub/add），5 天完成

**数据/环境**

- **FPGA 平台**：Digilent Arty A7-35T（Xilinx Artix-7 XC7A35T）
- **开发环境**：Intel Core i9-12900KF + 128 GiB DDR4 + Ubuntu 22.04.2
- **综合工具**：AMD Vivado 2024.2
- **仿真工具**：Verilator（周期精确）
- **编译器**：RISC-V GCC 工具链
- **对比基准**：
- ESP32-C3（RISC-V MCU，160 MHz，CoreMark = 408）
- VexRiscv-based SoC（200 MHz，CoreMark = 514）

**指标**

| 指标 | 数值 |
| --- | --- |
| 框架代码量 | **23 文件 / 2,681 行**（Verilog + C） |
| 许可证 | 单一 MIT（vs CFU Playground 多许可证） |
| RVProc CoreMark | **639** @ 235 MHz |
| CoreMark/MHz | **2.72**（vs ESP32-C3 2.55，VexRiscv 2.57） |
| N-Queens 加速比 | **18.1×** |
| N-Queens CFU 设计时间 | **3 天** |
| N-Queens CFU LUT 用量 | 1,142 |
| N-Queens CFU FF 用量 | 1,252 |
| N-Queens SoC 总 LUT 利用率 | **12.62%** |
| FFT 加速比 | **5.1×** |
| FFT CFU 设计时间 | **5 天** |
| FFT CFU LUT 用量 | 534 |
| FFT CFU FF 用量 | 598 |
| FFT SoC 总 LUT 利用率 | **9.56%** |

**主要结论**

1. **轻量级框架可行**：仅用 2,681 行代码即可搭建完整的 CFU 设计/仿真/验证流程，证明了"小而精"的设计哲学
2. **学习成本显著降低**：单一 MIT 许可证 + 显式依赖 + 仅 Verilog/C 两种语言，消除了 CFU Playground 的多许可证和复杂依赖问题
3. **敏捷开发周期短**：N-Queens CFU 3 天完成、FFT CFU 5 天完成，展示了框架的快速迭代能力
4. **CFU 接口标准化**：统一的 `en_i/funct3/funct7/src1/src2/stall/rslt` 接口使 CFU 可即插即用，为未来动态部分重构（DPR）奠定基础
5. **RVProc 性能优异**：CoreMark 639 @ 235 MHz，优于 ESP32-C3 和 VexRiscv，为 CFU 加速提供了坚实的基线处理器
6. **资源开销可控**：即使在小容量 Artix-7 35T 上，SoC + CFU 总 LUT 利用率仍低于 13%，剩余资源充足

**与自己课题的关系**

**极度相关（本文直接使用平台）**。本文是本课题毕设工作的**直接基础**——本课题使用的 CFU-Proving-Ground 框架正是该论文提出的平台。

| 对比维度 | CFU Proving Ground (Fujino & Kise, 2025) | 李凌翔毕设 |
| --- | --- | --- |
| **框架来源** | 本文提出 | 直接使用 |
| **处理器** | RVProc（自研 RV32IM + 分支预测） | RVProc（同上） |
| **CFU 接口** | `en/funct3/funct7/src1/src2/stall/rslt` | 完全相同 |
| **CFU 调用方式** | `cfu_op()` 内联汇编封装 | 完全相同 |
| **仿真工具** | Verilator | Verilator |
| **FPGA 板卡** | Arty A7-35T | **Nexys A7-100T**（同系列，更大容量） |
| **目标应用** | N-Queens、FFT（通用计算） | **CNN 推理（mac_dot、conv3x3）** |
| **CFU 设计复杂度** | 位运算逻辑（N-Queens）、蝶形运算（FFT） | **MAC 单元 + 累加器（INT8）** |
| **性能计数** | `pg_perf` 硬件计数器 | `pg_perf` 硬件计数器 |

**可直接复用的内容**：

1. **CFU 接口规范**：`cfu.v` 的端口定义、`cfu_op()` 的封装方式、`stall_o` 的用法，本课题已实现并验证
2. **`pg_perf` 性能计数**：本课题 microbenchmark 中测量 cycle 数的方法直接继承自该框架
3. **Verilator 仿真流程**：编译、运行、查看波形的完整流程完全一致
4. **Vivado 综合流程**：`report_utilization -hierarchical` 生成资源报告的方式可直接参考 Table II/III 的格式

**需明确区分/扩展的内容**：

1. **应用场景不同**：原文用 N-Queens 和 FFT 验证框架通用性，本课题用 CNN 推理（INT8 mac_dot、conv3x3）验证框架在 TinyML 领域的适用性
2. **CFU 复杂度不同**：原文的 CFU 是纯组合逻辑（位运算、蝶形），本课题的 CFU 包含时序逻辑（MAC 累加器、流水线），设计复杂度更高
3. **板卡差异**：原文用 Arty A7-35T（20,800 LUTs），本课题用 Nexys A7-100T（更大容量），本课题有更充裕的资源做方案 B 的并行扩展
4. **软件栈差异**：原文是纯 C 程序，本课题需要对接 TensorFlow Lite Micro（或手写 C 推理引擎）做 INT8 量化推理
5. **评估维度扩展**：原文只有加速比和资源利用率，本课题还需评估 INT8 精度保持、不同方案（单 MAC vs 并行 MAC）的对比

---