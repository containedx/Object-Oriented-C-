# STL PERFORMANCE ANALYSIS


###### assigned containers: vector, map, unordered_multiset 


## MAP

`at`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_at.png)

 
`operator[]`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_operator.png)

`empty`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_empty.png)

`size`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_size.png)

`max_size`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_maxsize.png)

`clear`

expected: O(n)

my result: O(lgN)

 ![](output/PLOTS/map_clear.png)

`insert`

expected: lgN / amortized O(1)

my result: O(1)

 ![](output/PLOTS/map_insert.png)

`erase`

expected: amortized constant/ log(size)

my result: O(1)

 ![](output/PLOTS/map_erase.png)

`swap`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_swap.png)

`count`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_count.png)

`find`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_find.png)

`equal_range`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_equalrange.png)

`lower_bound`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_lowerbound.png)
 
`upper_bound`

expected: O(lgN)

my results: O(lgN)

 ![](output/PLOTS/map_upperbound.png)


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








