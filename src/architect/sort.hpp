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
        std::vector<int> expected = {3, 4, 5, 12};
        std::vector<int> arr1 = {};
        std::vector<int> arr2 = {3, 4, 5, 12};
        auto result = ms_.merge(arr1, arr2);
        // for (const auto& i : result)
        //     std::cout << i << std::endl;
        return result == expected;
    }
};

//  in-place not quick
class QuickSort {
 private:
    int randomizePivot(int left_idx, int right_idx) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution<int> uid(left_idx, right_idx);
        return uid(generator);
    }

    int partition(std::vector<int>& arr, int left_idx, int right_idx) {
        auto pivot_idx = randomizePivot(left_idx, right_idx);
        std::swap(arr[pivot_idx], arr[right_idx]);
        auto pivot = arr[right_idx];
        auto i = left_idx;
        for (int j = left_idx; j < right_idx; ++j) {
            if (arr[j] < pivot)
                std::swap(arr[i++], arr[j]);
        }
        std::swap(arr[i], arr[right_idx]);
        return i;
    }

    int partition1(std::vector<int>& arr, int left_idx, int right_idx) {
        auto pivot_idx = randomizePivot(left_idx, right_idx);
        auto i = left_idx, j = right_idx;
        while (i <= j) {
            while (arr[i] < arr[pivot_idx]) ++i;
            while (arr[j] > arr[pivot_idx]) --j;
            if (i <= j) {
                std::swap(arr[i++], arr[j--]);
            }
        }

        return i - 1;
    }

    void helper(std::vector<int>& arr, int left_idx, int right_idx) {
        if (left_idx >= right_idx) return;
        auto pivot = partition(arr, left_idx, right_idx);
        helper(arr, left_idx, pivot - 1);
        helper(arr, pivot + 1, right_idx);
    }

 public:
    void run(std::vector<int>& arr) {
        helper(arr, 0, static_cast<int>(arr.size())-1);
    }

    friend class QuickSortTest;
};

class QuickSortTest {
 private:
    QuickSort qs_;

 public:
    QuickSortTest() = default;

    bool runPartitionTest() {
        std::vector<int> expected = {4, 5, 6, 7, 10};
        std::vector<int> arr = {4, 5, 10, 6, 7};
        auto pivot = qs_.partition1(arr, 0, static_cast<int>(arr.size())-1);
        std::cout << "pivot= " << pivot << std::endl;
        for (const auto& i : arr)
            std::cout << i << std::endl;
        return arr == expected;
    }
};


// best solution in leetcode
class CountingSort {
 public:
    CountingSort() = default;

    ~CountingSort() = default;

    void run(std::vector<int>& arr) {
        std::unordered_map<int, int> counts;
        auto min_value = *std::min_element(arr.begin(), arr.end());
        auto max_value = *std::max_element(arr.begin(), arr.end());

        for (const auto& e : arr)
            counts[e]++;

        int index = 0;
        for (int val = min_value; val <= max_value; ++val) {
            if (counts.find(val) != counts.end()) {
                while (counts[val] > 0) {
                    arr[index++] = val;
                    counts[val]--;
                }
            }
        }
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_SORT_HPP_
