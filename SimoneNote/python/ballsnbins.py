import random
import matplotlib.pyplot as plt
import matplotlib

# Set the matplotlib backend to Agg
matplotlib.use('Agg')

def balls_in_bins(num_balls, num_bins):
    """Simulerer fordelingen af bolde i beholdere.

    Args:
        num_balls: Antallet af bolde.
        num_bins: Antallet af beholdere.

    Returns:
        En liste med antallet af bolde i hver beholder.
    """
    bins = [0] * num_bins
    for _ in range(num_balls):
        bin_index = random.randint(0, num_bins - 1)
        bins[bin_index] += 1
    return bins

def experiment(num_balls_list, num_simulations):
    """Udfører flere simuleringer og beregner statistik.

    Args:
        num_balls_list: Liste af antallet af bolde.
        num_simulations: Antallet of simuleringer.

    Returns:
        En dictionary med N som nøgle og tuple med (antal simuleringer uden flere bolde i en beholder, samlet antal simuleringer) som værdi.
    """
    results = {}
    for num_balls in num_balls_list:
        num_bins = num_balls ** 2
        no_collision_count = 0
        for _ in range(num_simulations):
            bins = balls_in_bins(num_balls, num_bins)
            if all(count <= 1 for count in bins):
                no_collision_count += 1
        probability = no_collision_count / num_simulations
        results[num_balls] = (no_collision_count, num_simulations, probability)
    return results

def main():
    num_balls_list = [10, 20, 30, 40, 50]
    num_simulations = 1000

    experiment_results = experiment(num_balls_list, num_simulations)

    print("Experimental results:")
    for num_balls, (no_collision_count, total_simulations, probability) in experiment_results.items():
        print(f"N = {num_balls}: No Collision Count = {no_collision_count}, Total Simulations = {total_simulations}, Probability = {probability}")

    # Plotting the results
    balls = list(experiment_results.keys())
    probabilities = [experiment_results[b][2] for b in balls]

    plt.figure(figsize=(12, 6))
    plt.plot(balls, probabilities, 'o-', label='Probability of No Collision')
    plt.axhline(y=0.5, color='r', linestyle='--', label='Threshold (0.5)')
    plt.xscale('linear')
    plt.yscale('linear')
    plt.xlabel('Number of Balls (N)')
    plt.ylabel('Probability')
    plt.title('Probability of No Container Having More Than One Ball')
    plt.legend()
    plt.grid(True)
    plt.savefig('probability_no_collision.png')  # Save the plot to a file
    print("Plot saved as 'probability_no_collision.png'")

if __name__ == "__main__":
    main()