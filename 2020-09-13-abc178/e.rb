n = gets.to_i

m = (10**9) * 2 + 1

z_max = -m
z_min = m
w_max = -m
w_min = m

n.times do
  x, y = gets.chomp.split.map(&:to_i)
  z = x + y
  w = x - y
  z_max = z if z_max < z
  z_min = z if z_min > z
  w_max = w if w_max < w
  w_min = w if w_min > w
end

puts [z_max - z_min, w_max - w_min].max
