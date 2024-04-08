#ifndef __parser_hpp
#define __parser_hpp

// TODO: Delete this garbage code

#include <set>
#include "string"

static const std::set<std::string_view> operators = {"+", "-", "*", "/", "+=", "-=", "*=", "/=", "=", "++", "--", "~", "&", "|", "^", "<<", ">>", "<<=", ">>="};
static const std::set<std::string_view> types = {"int8", "uint8", "int16", "int32", "uint32", "int64", "uint64", "float8", "float16", "float32", "float64", "float128", "string"};

#endif // __parser_hpp
