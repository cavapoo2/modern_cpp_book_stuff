#pragma once
template <typename C, typename... Args>
void push_back_r(C &c, Args &&... args)
{
    (c.push_back(args), ...);
}
template <typename C, typename... Args>
void push_back_l(C &c, Args &&... args)
{
    (..., c.push_back(args));
}