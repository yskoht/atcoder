s = gets.to_i

h = {
  0 => 0,
  1 => 0,
  2 => 0,
  3 => 1,
}

3.upto(s) do |x|
  r = 0
  3.upto(x-3) do |i|
    t = x - i
    r += h[t]
  end
  h[x] = r + 1
end

puts h[s] % 1000000007
