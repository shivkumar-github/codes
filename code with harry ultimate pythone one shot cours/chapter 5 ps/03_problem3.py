# can a set have 18 and '18' both ->> yes as they are different data types they are not duplicates
# myset = { 18, '18'}
myset = {20, 20.0, '20'}
print(myset)
# but 20 and 20.0 are equal because while compairing a integer with floating they convert the int to floating point hence gives true 


# #include<iostream>
# using namespace std;
# int main(){
#         // cout << (1 == 1.0);
#         // cout << (1 == '1');
#         cout << (49 == '1'); // while comparing a character with integer cpp compares with ascii value of character with number 
#         return 0;
# }