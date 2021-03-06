n = gets.to_i
a = gets.chomp.split.map(&:to_i)
a2 = a.map{|x| x * x}

_s = 0
s = a.reverse.map{ |x| _s += x; _s }.reverse

_s2 = 0
s2 = a2.reverse.map{ |x| _s2 += x; _s2 }.reverse

res = 0

(n-1).times do |i|
  t = n - 1 - i
  res += a2[i] * t
  res += s2[i+1]
  res -= 2 * a[i] * s[i+1]
end

puts res
