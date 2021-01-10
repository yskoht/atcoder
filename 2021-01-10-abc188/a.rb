x, y = gets.chomp.split.map(&:to_i)
if (x - y).abs <= 2
  puts "Yes"
else
  puts "No"
end
