n = gets.to_i
x = gets.chomp.split.map(&:to_i)

m = 0
u = 0
t = 0

x.each do |y|
  a = y.abs
  m += a
  u += a ** 2
  t = a if t < a
end

puts m
puts Math.sqrt(u)
puts t
