x, y, _, _, _ = gets.chomp.split.map(&:to_i)
ps = gets.chomp.split.map(&:to_i).sort.reverse[0, x]
qs = gets.chomp.split.map(&:to_i).sort.reverse[0, y]
rs = gets.chomp.split.map(&:to_i).sort.reverse

arr = ps + qs + rs
puts arr.sort.reverse[0, x+y].inject(:+)
