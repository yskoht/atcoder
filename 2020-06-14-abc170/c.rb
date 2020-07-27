x, n = gets.chomp.split.map(&:to_i)

a = []
a = gets.chomp.split.map(&:to_i) if n != 0

i = 0
loop do
  t = x - i
  if !a.include?(t)
    puts t
    break
  end

  t = x + i
  if !a.include?(t)
    puts t
    break
  end

  i += 1
end
