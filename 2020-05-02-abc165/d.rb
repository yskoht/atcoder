a, b, n = gets.chomp.split.map(&:to_i)

x = [b - 1, n].min
b = b.to_f

t = (a * x / b).floor - a * (x / b).floor

puts t