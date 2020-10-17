n = gets.to_i
a = gets.chomp.split.map(&:to_i).uniq

loop do
  x = a.max
  y = a.min

  if x == y
    puts x
    break
  end

  a = a.map { |t|
    k = t % y
    y - k
  }.uniq
end
