#include<vector>
using namespace std;
class Solution {
public:
    void position(vector<int> &v, int i1, int i2, int value, int &i3, int &i4)
    {
        if (value > v[i2 - 1])
        {
            i3 = i4 = i2;
            return;
        }
        if (value < v[i1])
        {
            i3 = i4 = -1;
            return;
        }
        while (1)
        {
            if (i1 == i2 - 1)
            {
                i3 = i1;
                i4 = i2;
                break;
            }
            int tmp = (i1 + i2) / 2;
            if (v[tmp] < value)
            {
                i1 = tmp;
            }
            // else if (v[tmp] > value)
            // {
            //     i2 = tmp;
            // }
            else
            {
                i3 = tmp - 1;
                i4 = tmp + 1;
                break;
            }
        }

        if (i4 - i3 == 2)
        {
            while (1)
            {
                if (i3 < 0)
                    break;
                if (v[i3] == value)
                    i3 = i3 - 1;
                else
                    break;
            }

            while (1)
            {
                if (i4 > (v.size() - 1))
                    break;
                if (v[i4] == value)
                    i4 = i4 + 1;
                else
                    break;
            }
        }
    }

    void num_(int i1, int i2, int len, int& small,int& more)
    {
        if (i2 == -1)
        {
            small = 0;
            more = len;
        }
        else if( i1 == len)
        {
            small = len;
            more = 0;
        }
        else{
            small = i1 +1;
            more = len - i2;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int index1 = 0, index2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();

        while(1){
            int num = nums1[len1/2];
            int small1 = len1/2;
            int more1 = len1 -(len1/2+1);

            int i1,i2,small2,more2;
            position(nums2,0,nums2.size(),num,i1,i2);
            num_(i1,i2,len2,small2,more2);

            if (small1 + small2 == more1 + more2)
            {
                return num;
            }

            
        }
    }
        
};

