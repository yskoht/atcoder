n = gets.to_i

r = 0

1.upto(n-1) do |i|
  r += n.to_f / (n - i)
end

puts r
