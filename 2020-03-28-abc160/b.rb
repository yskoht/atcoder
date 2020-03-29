x = gets.chomp.to_i

a = x / 500
b = (x % 500) / 5

puts a * 1000 + b * 5
