n, m = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)

sum = a.inject(&:+)
if n >= sum
  puts n - sum
else
  puts -1
end