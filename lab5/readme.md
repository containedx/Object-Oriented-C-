#STL PERFORMANCE ANALYSIS
######assigned containers: vector, map, unordered_multiset 


##VECTOR

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


##MAP

`at`
O(lgN)
 
`operator[]`
O(lgN)

`empty`
O(1)

`size`
O(1)

`max_size`
O(1)

`clear`
linear

`insert`
lgN / amortized constant

`erase`
amortized constant/ log(size)

`swap`
O(1)

`count`
O(lgN)

`find`
O(lgN)

`equal_range`
O(lgN)

`lower_bound`
O(lgN)

`upper_bound`
O(lgN)


##UNORDERED MULTISET

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








