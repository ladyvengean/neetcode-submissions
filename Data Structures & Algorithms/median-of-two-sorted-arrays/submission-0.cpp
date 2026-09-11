class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        int leftElements = (n1 + n2 + 1) / 2;

        while (low <= high) {

            // How many elements are we taking from nums1?
            int cut1 = (low + high) / 2;

            // Remaining elements needed from nums2
            int cut2 = leftElements - cut1;

            // Four important values

            int left1;
            int right1;
            int left2;
            int right2;

            if (cut1 == 0)
                left1 = INT_MIN;
            else
                left1 = nums1[cut1 - 1];

            if (cut1 == n1)
                right1 = INT_MAX;
            else
                right1 = nums1[cut1];

            if (cut2 == 0)
                left2 = INT_MIN;
            else
                left2 = nums2[cut2 - 1];

            if (cut2 == n2)
                right2 = INT_MAX;
            else
                right2 = nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd total number of elements
                if ((n1 + n2) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even total number of elements
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // We took too many elements from nums1
            if (left1 > right2) {
                high = cut1 - 1;
            }

            // We took too few elements from nums1
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
