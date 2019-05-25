#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
less<int>, //change for custom Comparator
rb_tree_tag,
tree_order_statistics_node_update>
statistic_tree;

signed main()
{
	statistic_tree st;
	st.insert(5); 
    st.insert(2); 
    st.insert(6); 
    st.insert(4);
    st.insert(8);
    
    cout<<"All elements\n";
    for(auto u:st)
    cout<<u<<" ";
    cout<<endl;
    
    // Remember that element itslef is included in upper_bound 
    // so for strictly less do order_of_key.
    
    // value at 3rd index in sorted array. 
    cout << "The value at 3rd index ::" 
         << *st.find_by_order(3) << endl; 
  
    // index of number 6 
    cout << "The index of number 6::" 
         << st.order_of_key(6) << endl; 
         
    //Number of elements after or at the position of 6
    cout << "The number of elements at or after position of 6::" 
         << st.size()-st.order_of_key(6) << endl;      
    
    //Number of elements strictly before the position of 6
    cout << "The number of elements strictly before the position of 6::" 
         <<  st.order_of_key(6) << endl;      
    
    //Number of elements after or at the position of 7
    cout << "The number of elements at or after position of 7::" 
         << st.size()-st.order_of_key(7) << endl;      
    
    //Number of elements strictly before the position of 7
    cout << "The number of elements strictly before the position of 7::" 
         <<  st.order_of_key(7) << endl;      
    
    // number 7 not in the set but it will show the  
    // index number if it was there in sorted array. 
    cout << "The index of number seven ::"
         << st.order_of_key(7) << endl; 
    
    
    auto it=st.find(2);
    st.erase(it);
    
    cout<<"All elements\n";
    for(auto u:st)
    cout<<u<<" ";
    cout<<endl;
      
    return 0; 
}