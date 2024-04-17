# 乱七八糟的oi东西


## 哈希
> `mod=1000000007`
> `key=131`
## string

## `string::find` &&`string::rfind`
> `string::find`返回的type是`size_t`所以谨慎使用`auto pos=str.find(sth);`建议使用`int pos =
> str.find(sth)`

`string::find`查找第一个出现字串的位置，`string::rfind`查找字串最后出现的位置.

如果没有找到，会返回一个`string::npos`,其类型为`size_t`

## cout
可以使用`cout<<R"(多行内容)"`来输出多行，而不用多个`cout`语句
