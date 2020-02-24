as = gets.chomp.split.map(&:to_i)
if as.uniq.size == 2
  puts 'Yes'
else
  puts 'No'
end

