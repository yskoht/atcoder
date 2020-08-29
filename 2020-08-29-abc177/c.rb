n = gets.to_i
a = gets.chomp.split.map(&:to_i)

s = []

t = 0
a.each do |x|
  t += x
  s.push t
end

m = 10 ** 9 + 7

res = 0
(n-1).times do |i|
  res += a[i] * (s[-1] - s[i])
  res %= m
end

puts res
