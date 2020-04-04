n, a, b = gets.chomp.split.map(&:to_i)

x = n / (a + b) * a

y = n % (a + b)
if y < a
  x += y
else
  x += a
end

puts x
