# STL PERFORMANCE ANALYSIS


###### assigned containers: vector, map, unordered_multiset 


## MAP

`at`
O(lgN)
 ![](output/PLOTS/map _ at.png)
 
 
`operator[]`
O(lgN)
 ![](output/PLOTS/map _ operator.png)

`empty`
O(1)
 ![](output/PLOTS/map_empty.png)

`size`
O(1)
 ![](output/PLOTS/map _ size.png)

`max_size`
O(1)
 ![](output/PLOTS/map_maxsize.png)

`clear`
O(n)
 ![](output/PLOTS/map _ clear.png)

`insert`
lgN / amortized constant
 ![](output/PLOTS/map _ insert.png)

`erase`
amortized constant/ log(size)
 ![](output/PLOTS/map _ erase.png)

`swap`
O(1)
 ![](output/PLOTS/map _ swap.png)

`count`
O(lgN)
 ![](output/PLOTS/map _ count.png)

`find`
O(lgN)
 ![](output/PLOTS/map _ find.png)

`equal_range`
O(lgN)
 ![](output/PLOTS/map _ equalrange.png)

`lower_bound`
O(lgN)
 ![](output/PLOTS/map _ lowerbound.png)
 
`upper_bound`
O(lgN)
 ![](output/PLOTS/map _ upperbound.png)


## VECTOR

`at` 
O(1)

`operator[]`
O(1)

`front`
O(1)

`back`
O(1)

`empty`
O(1)

`size`
O(1)

`max_size`
O(1)

`shrink_to_fit`
linear O(n)

`clear`
linear

`insert`
linear

`erase`
linear

`push_back`
amortized constant

`pop_back`
O(1)

`resize`
linear

`swap`
O(1)



## UNORDERED MULTISET

`empty`
O(1)

`size`
O(1)

`max_size`
O(1)

`clear`
linear

`insert`
O(1) 

`erase`
O(1)

`swap`
O(1)

`count`
linear O(n)

`find`
O(1) at worst linear

`equal_range`
linear O(n)

`rehash`
O(n) worst ^2

`reserve`
O(n)








