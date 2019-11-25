# STL PERFORMANCE ANALYSIS


###### assigned containers: vector, map, unordered_multiset 


## MAP

`at`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_at.png)  
 ![](output/PLOTS/RELEASE_map_at.png)

 
`operator[]`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_operator.png)
  ![](output/PLOTS/RELEASE_map_operator.png)

`empty`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_empty.png)
  ![](output/PLOTS/RELEASE_map_empty.png)

`size`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_size.png)
  ![](output/PLOTS/RELEASE_map_size.png)

`max_size`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_maxsize.png)
  ![](output/PLOTS/RELEASE_map_maxsize.png)

`clear`

expected: O(n)

my result: O(lgN)

 ![](output/PLOTS/map_clear.png)
  ![](output/PLOTS/RELEASE_map_clear.png)

`insert`

expected: lgN / amortized O(1)

my result: O(1)

 ![](output/PLOTS/map_insert.png)
  ![](output/PLOTS/RELEASE_map_insert.png)

`erase`

expected: amortized constant/ log(size)

my result: O(1)

 ![](output/PLOTS/map_erase.png)
  ![](output/PLOTS/RELEASE_map_erase.png)

`swap`

expected: O(1)

my result: O(1)

 ![](output/PLOTS/map_swap.png)
  ![](output/PLOTS/RELEASE_map_swap.png)

`count`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_count.png)
  ![](output/PLOTS/RELEASE_map_count.png)

`find`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_find.png)
  ![](output/PLOTS/RELEASE_map_find.png)

`equal_range`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_equalrange.png)
  ![](output/PLOTS/RELEASE_map_equalrange.png)

`lower_bound`

expected: O(lgN)

my result: O(lgN)

 ![](output/PLOTS/map_lowerbound.png)
  ![](output/PLOTS/RELEASE_map_lowerbound.png)
 
`upper_bound`

expected: O(lgN)

my results: O(lgN)

 ![](output/PLOTS/map_upperbound.png)
  ![](output/PLOTS/RELEASE_map_upperbound.png)


## VECTOR

`at` 
O(1)

![](output/PLOTS/vector_at.png)

`operator[]`
O(1)

![](output/PLOTS/vector_operator.png)

`front`
O(1)

![](output/PLOTS/vector_front.png)

`back`
O(1)

![](output/PLOTS/vector_back.png)

`empty`
O(1)

![](output/PLOTS/vector_empty.png)

`size`
O(1)

![](output/PLOTS/vector_size.png)

`max_size`
O(1)

![](output/PLOTS/vector_maxsize.png)

`shrink_to_fit`
linear O(n)

![](output/PLOTS/vector_shrink.png)

`clear`
linear

![](output/PLOTS/vector_clear.png)

`insert`
linear

![](output/PLOTS/vector_insert.png)

`erase`
linear

![](output/PLOTS/vector_erase.png)

`push_back`
amortized constant

![](output/PLOTS/vector_pushback.png)

`pop_back`
O(1)

![](output/PLOTS/vector_popback.png)

`resize`
linear

![](output/PLOTS/vector_resize.png)

`swap`
O(1)

![](output/PLOTS/vector_swap.png)



## UNORDERED MULTISET

`empty`
O(1)

![](output/PLOTS/unorderedmultiset_empty.png)

`size`
O(1)

![](output/PLOTS/unorderedmultiset_size.png)


`max_size`
O(1)

![](output/PLOTS/unorderedmultiset_maxsize.png)


`clear`
linear

![](output/PLOTS/unorderedmultiset_clear.png)


`insert`
O(1) 

![](output/PLOTS/unorderedmultiset_insert.png)


`erase`
O(1)

![](output/PLOTS/unorderedmultiset_erase.png)


`swap`
O(1)

![](output/PLOTS/unorderedmultiset_swap.png)


`count`
linear O(n)

![](output/PLOTS/unorderedmultiset_count.png)


`find`
O(1) at worst linear

![](output/PLOTS/unorderedmultiset_find.png)


`equal_range`
linear O(n)

![](output/PLOTS/unorderedmultiset_equalrange.png)


`rehash`
O(n) worst ^2

![](output/PLOTS/unorderedmultiset_rehash.png)


`reserve`
O(n)

![](output/PLOTS/unorderedmultiset_reserve.png)








