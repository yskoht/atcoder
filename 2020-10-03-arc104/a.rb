a, b = gets.chomp.split.map(&:to_i)

x = (a + b) / 2
y = a - x

puts "#{x} #{y}"
