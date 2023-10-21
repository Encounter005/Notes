#include "StrVec.h"

// 初始化静态成员
std::allocator<std::string> StrVec::alloc;
void StrVec::reallocate() {
    std::string *newdata = nullptr;
    // 数组为空的情况
    if ( elements == nullptr || cap == nullptr || first_free == nullptr ) {
        newdata    = alloc.allocate( 1 );
        elements   = newdata;
        first_free = newdata;
        cap        = newdata + 1;
    } else {
        // 如果不为空，那就分配一个原数组2倍的空间
        newdata = alloc.allocate( size() * 2 );
        // 新内存空闲位置
        auto dest = newdata;
        // 旧内存有效位置
        auto src = elements;
        // 通过移动操作将旧数据放入新内存中
        for ( size_t i = 0; i != size(); i++ ) {
            alloc.construct( dest++, std::move( *src++ ) );
        }

        // 清空旧内存
        free();

        elements   = newdata;
        first_free = dest;
        cap        = elements + size() * 2;
    }
}

void StrVec::free() {
    // 如果首元素不是空指针
    if ( elements != nullptr ) {
        auto dest = elements;
        // 先删除每一个元素分配的内存
        for ( size_t i = 0; i < size(); i++ ) {
            alloc.destroy( dest + i );
        }
        // 再删除掉整块内存
        alloc.deallocate( elements, cap - elements );
        elements   = nullptr;
        first_free = nullptr;
        cap        = nullptr;
    }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(
    const std::string *st, const std::string *ed ) {
    auto newdata = alloc.allocate( ed - st );
    // 将原数据用来初始化新的内存空间
    auto first_free = std::uninitialized_copy( st, ed, newdata );
    return std::make_pair( newdata, first_free );
}

StrVec::StrVec( const StrVec &other ) {
    // 将形参数据拷贝给自己
    auto res   = alloc_n_copy( other.begin(), other.end() );
    elements   = res.first;
    first_free = res.second;
    cap        = res.second;
}

StrVec::StrVec( StrVec &&other ) {
    auto res   = alloc_n_copy( other.begin(), other.end() );
    elements   = res.first;
    first_free = res.second;
    cap        = res.second;
}

StrVec &StrVec::operator=( StrVec &&other ) noexcept {
    if ( this == &other ) {
        return *this;
    }

    auto res   = alloc_n_copy( other.begin(), other.end() );
    elements   = res.first;
    first_free = res.second;
    cap        = res.second;
    return *this;
}

StrVec &StrVec::operator=( const StrVec &other ) {
    // 防止自赋值的情况
    if ( this == &other ) {
        return *this;
    }

    // 拷贝内存
    auto res   = alloc_n_copy( other.begin(), other.end() );
    elements   = res.first;
    first_free = res.second;
    cap        = res.second;
    return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::push_back( const std::string &value ) {
    chk_n_alloc();
    alloc.construct( first_free++, value );
}

void StrVec::pop_back( std::string &other ) {
    if ( first_free == nullptr ) {
        return;
    }

    if ( size() == 1 ) {
        other = *elements;
        alloc.destroy( elements );
        elements   = nullptr;
        first_free = nullptr;
        return;
    }

    other = *( --first_free );
    alloc.destroy( first_free );
}

std::string &StrVec::operator[]( size_t pos ) const {
    if ( pos < size() ) {
        auto it = elements;
        std::advance( it, pos );
        return *it;
    } else {
        assert(pos >= size());
    }
}
