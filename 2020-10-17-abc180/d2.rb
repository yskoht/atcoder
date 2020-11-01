x, y, a, b = gets.chomp.split.map(&:to_i)

t = b.to_f / (a.to_f - 1)
m = [y, t].min.to_f
n1 = [(Math.log(m / x, a)).floor, 0].max
k = x * (a ** n1)
n2 = ((y - 1 - k) / b).floor

puts n1 + n2
