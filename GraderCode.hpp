#pragma once

#include <memory>
#include <vector>
#include <map>
#include <cstdint>
#include <array>

namespace grader {

	uint32_t val_at(int i);

	class NQueens {
	public:
		virtual ~NQueens() {}
		virtual bool next_permutation(std::vector<uint32_t>& v) = 0;
		virtual bool is_valid(const std::vector<uint32_t>&) = 0;
	};

	std::unique_ptr<NQueens> get_nq();
}