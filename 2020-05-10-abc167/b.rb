a, b, c, k = gets.chomp.split.map(&:to_i)
res = 0

res += [k, a].min
k -= a

if k > 0
  k -= b
end

if k > 0
  res -= k
end

puts res
