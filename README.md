# 模拟卷积神经网络中的操作
昨天看到了博客https://blog.csdn.net/rogerchen1983/article/details/79353861 ，感觉里面的卷积、池化和激活操作都可以用C++模拟，所以花了3个小时写出代码。<br>
在matrix二维数组中用5*5double矩阵模拟字符'x'的形状，主对角线与副对角线是1，其余部分是-1。<br>
首先在5*5矩阵中取下9个3*3矩阵，这里是整个代码的核心。外面两层i, j循环用于3*3矩阵的大循环，里面两层k, t循环用于每一个3*3矩阵的内部循环。<br>
然后是提取feature map，即进行卷积操作。思路与上述四重循环相同。<br>
再进行池化操作，由于提取出的feature map已经是3*3矩阵，并不需要池化来进一步简化运算，所以此处的池化操作仅仅是写出池化的算法步骤<br>
最后进行激活操作，激活函数采用ReLU线性整流函数，依然对feature map进行激活操作。<br>
算法完成！
