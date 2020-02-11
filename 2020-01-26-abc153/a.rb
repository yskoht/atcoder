h, a = gets.chomp.split.map(&:to_i)
k = h / a
k += 1 if h % a != 0
puts k
