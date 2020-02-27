n, r = gets.chomp.split.map(&:to_i)

puts((n >= 10) ? r : r + 100 * (10 - n))
