# -*- coding: utf-8 -*-
"""
Created on Fri Apr 28 19:30:35 2017

@author: Administrator
"""
# 第三批高级case0测试费用流时间
# 使用最优解服务器位置,cost应为67826

import datetime
import networkx as nx

fh=open("gcase0_simplex.txt", 'rb') # gcase0_simplex.txt存放了所有边数据,但不包括源点和汇点
G=nx.read_edgelist(fh, nodetype=int, create_using=nx.DiGraph()) # 读入有向图
fh.close()

time_begin = datetime.datetime.now()

# 1.网络单纯形
G.add_node(1682, demand=-11755) # 加入超级源
G.add_node(1681, demand=11755) # 加入超级汇
flowcost, flowdict = nx.network_simplex(G) # 网络单纯形计算最小费用
# 1.网络单纯形 end

# 2.max_flow_min_cost
#mincostFlow = nx.max_flow_min_cost(G, 1682, 1681)
#flowcost = nx.cost_of_flow(G, mincostFlow)
# 2.max_flow_min_cost end

time_end = datetime.datetime.now()

print('cost:', flowcost)            # 打印费用流
print('time:', time_end-time_begin) # 打印用时
