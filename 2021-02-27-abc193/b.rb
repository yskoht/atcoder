n = gets.to_i
M = 10_000_000_000
m = M
n.times do
  a, p, x = gets.chomp.split.map(&:to_i)
  m = [m, p].min if x - a > 0
end

if m == M
  puts -1
else
  puts m
end
