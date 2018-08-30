
#include "GraderCode.hpp"

// Notice: We are using a namespace here
namespace grader {
	// Solutions for board size 1x1 to 14x14
	std::array<uint32_t, 14> vals{
	1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680,
	14200, 73712, 365596,
	};

	// Function that returns the solution per board size (i) passed in
	uint32_t val_at(int i) {
		return vals[i];
	}

	/* 
	** Class that does all of the NQueens math for us, inherits from NQueens class in the header. 

	** the is_valid() method, which takes a const reference to a std::vector, and returns true if
 	   the numbers in the vector are a valid solution for the N Queens problem, and false otherwise.
	
	** The next_permutation() method, which takes a reference to a vector, and attempts to generate the next
 *      permutation. If it succeeds, it will return true. If no more permutations exist, it will return false instead.
	*/
	class NQueensImpl : public NQueens {
	public:
		virtual bool next_permutation(std::vector<uint32_t>& v) override {
			intptr_t n = v.size();
			if (0 == n || 1 == n)
				return false;

			if (2 == n) {
				std::swap(v[0], v[1]);
				return false;
			}

			auto i = n - 2;
			auto j = n - 1;

			for (; i >= 0; --i)
				if (v[i] < v[i + 1])
					break;

			if (i < 0)
				return false;

			for (; j >= 0; --j)
				if (v[i] < v[j])
					break;

			if (j < 0)
				return false;

			std::swap(v[i], v[j]);
			std::reverse(v.begin() + i + 1, v.end());

			return true;
		}

		virtual bool is_valid(const std::vector<uint32_t>& v) override {
			for (int col = 0; col < v.size(); ++col) {
				auto row = v[col];
				for (auto j = 0; j < v.size(); ++j) {
					auto idx = v.size() - j - 1;
					if (idx == col)
						continue;

					int other_row = v[idx];
					int delta_row = other_row - row;
					int delta_col = col - idx;
					if (delta_row == delta_col || delta_row == -delta_col)
						return false;
				}
			}

			return true;
		}
	};


	std::unique_ptr<NQueens> get_nq()
	{
		return std::make_unique<NQueensImpl>();
	}
}
