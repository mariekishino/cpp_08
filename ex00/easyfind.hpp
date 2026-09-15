#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
/*
const container 

begin()/end()

const iterator
std::find()

見つかった位置、またはend()

*/
// コンテナ型を一般化
template <typename T>
typename T::iterator		// easyfindの戻り値型
easyfind(T& container, int value)
{
	typename T::iterator found = 	// iterator変数
		std::find(					// STLアルゴリズム
			container.begin(),		// 検索開始iterator 
			container.end(),		// 検索終了iterator
			value
		);

	if (found == container.end())
		throw std::runtime_error("easyfind: value not found");
	return found;					// 見つかった位置を返す
}


#endif

