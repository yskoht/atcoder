n = gets.to_i
s = 0
n.times do
  a, b = gets.chomp.split.map(&:to_i)
  m = b - a + 1
  s += m * (a + b) / 2
end

puts s
