x, y, a, b = gets.chomp.split.map(&:to_i)

c = 0
while x * a <= x + b && x < y
  x *= a
  c += 1
end

puts c + ((y - 1 - x) / b).floor