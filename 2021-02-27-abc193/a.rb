a, b = gets.chomp.split.map(&:to_i)
r = (a - b).to_f / a.to_f
puts r * 100
