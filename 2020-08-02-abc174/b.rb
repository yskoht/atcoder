n, d = gets.chomp.split.map(&:to_i)
d *= d
cnt = 0
n.times do
  x, y = gets.chomp.split.map(&:to_i)
  t = x ** 2 + y ** 2
  cnt += 1 if t <= d
end
puts cnt
