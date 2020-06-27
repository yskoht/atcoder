n, k = gets.chomp.split.map(&:to_i)
ps = gets.chomp.split.map(&:to_i)

ps.sort!
puts ps[0...k].inject(:+)