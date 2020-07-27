x, y = gets.chomp.split.map(&:to_i)

f = false
0.upto(100) do |a|
  0.upto(100) do |b|
    if (2 * a + 4 * b == y) && (a + b == x)
      f = true
      break
    end
  end
end

if f
  puts "Yes"
else
  puts "No"
end
