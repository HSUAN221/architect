// Copyright (c)
#ifndef SRC_ARCHITECT_SORT_HPP_
#define SRC_ARCHITECT_SORT_HPP_
namespace architect {

class MergeSortTest;
class MergeSort {
 private:
    std::vector<int> merge(const std::vector<int>& arr1, const std::vector<int>& arr2) {
        std::vector<int> merged_arr;
        merged_arr.reserve(arr1.size() + arr2.size());
        auto iter1 = arr1.begin();
        auto iter2 = arr2.begin();

        while (iter1 != arr1.end() && iter2 != arr2.end()) {
            const auto& arr1_val = *iter1;
            const auto& arr2_val = *iter2;
            if (arr1_val <= arr2_val) {
                merged_arr.push_back(arr1_val);
                iter1++;
            } else {
                merged_arr.push_back(arr2_val);
                iter2++;
            }
        }

        if (iter1 == arr1.end()) {
            while (iter2 != arr2.end()) {
                const auto& arr2_val = *iter2;
                merged_arr.push_back(arr2_val);
                iter2++;
            }
        } else {
            while (iter1 != arr1.end()) {
                const auto& arr1_val = *iter1;
                merged_arr.push_back(arr1_val);
                iter1++;
            }
        }
        return merged_arr;
    }

 public:
    MergeSort() = default;

    std::vector<int> run(const std::vector<int>& arr) {
        if (arr.size() == 1) return arr;
        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());
        auto left_is_sorted = run(left);
        auto right_is_sorted = run(right);
        return merge(left_is_sorted, right_is_sorted);
    }

    friend class MergeSortTest;
};

class MergeSortTest {
 private:
    MergeSort ms_;

 public:
    MergeSortTest() = default;

    bool runMergeTest() {
        std::vector<int> expected = {1, 3, 4, 5, 8, 10, 12};
        std::vector<int> arr1 = {1, 8, 10};
        std::vector<int> arr2 = {3, 4, 5, 12};
        auto result = ms_.merge(arr1, arr2);
        for (const auto& i : result)
            std::cout << i << std::endl;
        return result == expected;
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_SORT_HPP_
